static int
F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_9 * V_10 ;
int V_11 , V_12 ;
V_11 = F_2 ( V_2 , V_3 , V_5 , NULL , 0x3724 ,
16 , V_13 , & V_10 ) ;
* V_8 = F_3 ( V_10 ) ;
if ( V_11 )
return V_11 ;
V_10 -> V_14 = F_4 ( V_2 ) -> V_14 ;
F_5 ( V_10 , 0x0028 , 0x00000001 | ( V_10 -> V_14 << 24 ) ) ;
F_5 ( V_10 , 0x035c , 0xffff0000 ) ;
F_5 ( V_10 , 0x03c0 , 0x0fff0000 ) ;
F_5 ( V_10 , 0x03c4 , 0x0fff0000 ) ;
F_5 ( V_10 , 0x049c , 0x00000101 ) ;
F_5 ( V_10 , 0x04b0 , 0x00000111 ) ;
F_5 ( V_10 , 0x04c8 , 0x00000080 ) ;
F_5 ( V_10 , 0x04cc , 0xffff0000 ) ;
F_5 ( V_10 , 0x04d0 , 0x00000001 ) ;
F_5 ( V_10 , 0x04e4 , 0x44400000 ) ;
F_5 ( V_10 , 0x04fc , 0x4b800000 ) ;
for ( V_12 = 0x0510 ; V_12 <= 0x051c ; V_12 += 4 )
F_5 ( V_10 , V_12 , 0x00030303 ) ;
for ( V_12 = 0x0530 ; V_12 <= 0x053c ; V_12 += 4 )
F_5 ( V_10 , V_12 , 0x00080000 ) ;
for ( V_12 = 0x0548 ; V_12 <= 0x0554 ; V_12 += 4 )
F_5 ( V_10 , V_12 , 0x01012000 ) ;
for ( V_12 = 0x0558 ; V_12 <= 0x0564 ; V_12 += 4 )
F_5 ( V_10 , V_12 , 0x000105b8 ) ;
for ( V_12 = 0x0568 ; V_12 <= 0x0574 ; V_12 += 4 )
F_5 ( V_10 , V_12 , 0x00080008 ) ;
for ( V_12 = 0x0598 ; V_12 <= 0x05d4 ; V_12 += 4 )
F_5 ( V_10 , V_12 , 0x07ff0000 ) ;
F_5 ( V_10 , 0x05e0 , 0x4b7fffff ) ;
F_5 ( V_10 , 0x0620 , 0x00000080 ) ;
F_5 ( V_10 , 0x0624 , 0x30201000 ) ;
F_5 ( V_10 , 0x0628 , 0x70605040 ) ;
F_5 ( V_10 , 0x062c , 0xb0a09080 ) ;
F_5 ( V_10 , 0x0630 , 0xf0e0d0c0 ) ;
F_5 ( V_10 , 0x0664 , 0x00000001 ) ;
F_5 ( V_10 , 0x066c , 0x00004000 ) ;
F_5 ( V_10 , 0x0678 , 0x00000001 ) ;
F_5 ( V_10 , 0x0680 , 0x00040000 ) ;
F_5 ( V_10 , 0x0684 , 0x00010000 ) ;
for ( V_12 = 0x1b04 ; V_12 <= 0x2374 ; V_12 += 16 ) {
F_5 ( V_10 , ( V_12 + 0 ) , 0x10700ff9 ) ;
F_5 ( V_10 , ( V_12 + 4 ) , 0x0436086c ) ;
F_5 ( V_10 , ( V_12 + 8 ) , 0x000c001b ) ;
}
F_5 ( V_10 , 0x2704 , 0x3f800000 ) ;
F_5 ( V_10 , 0x2718 , 0x3f800000 ) ;
F_5 ( V_10 , 0x2744 , 0x40000000 ) ;
F_5 ( V_10 , 0x2748 , 0x3f800000 ) ;
F_5 ( V_10 , 0x274c , 0x3f000000 ) ;
F_5 ( V_10 , 0x2754 , 0x40000000 ) ;
F_5 ( V_10 , 0x2758 , 0x3f800000 ) ;
F_5 ( V_10 , 0x2760 , 0xbf800000 ) ;
F_5 ( V_10 , 0x2768 , 0xbf800000 ) ;
F_5 ( V_10 , 0x308c , 0x000fe000 ) ;
F_5 ( V_10 , 0x3108 , 0x000003f8 ) ;
F_5 ( V_10 , 0x3468 , 0x002fe000 ) ;
for ( V_12 = 0x3484 ; V_12 <= 0x34a0 ; V_12 += 4 )
F_5 ( V_10 , V_12 , 0x001c527c ) ;
return 0 ;
}
static int
F_6 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_15 * V_16 ;
int V_11 ;
V_11 = F_7 ( V_2 , V_3 , V_5 , true , & V_16 ) ;
* V_8 = F_3 ( V_16 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_8 ( F_3 ( V_16 ) , NULL , 32 * 4 , 16 ,
V_13 , & V_16 -> V_17 ) ;
if ( V_11 )
return V_11 ;
F_9 ( V_16 ) -> V_18 = 0x00001000 ;
F_9 ( V_16 ) -> V_19 = V_20 ;
F_10 ( V_16 ) -> V_21 = & V_22 ;
F_10 ( V_16 ) -> V_23 = V_24 ;
F_10 ( V_16 ) -> V_25 = V_26 ;
return 0 ;
}
