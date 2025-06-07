.include "hdr.asm"

.section ".rodata1" superfree

tilfont:
.incbin "pvsneslibfont.pic"

palfont:
.incbin "pvsneslibfont.pal"

.ends


.section ".rodata2" superfree

tileset:
.incbin "tiled/tileset00.pic"
tilesetend:

tilepal:
.incbin "tiled/tileset00.pal"

map00:
.incbin "tiled/map_1.m16"

tileset_att:
.incbin "tiled/map00.b16"

tileset_def:
.incbin "tiled/map00.t16"

.ends
