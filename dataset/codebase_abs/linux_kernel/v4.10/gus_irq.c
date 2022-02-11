T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned char V_5 ;
int V_6 = 100 ;
int V_7 = 0 ;
V_8:
V_5 = F_2 ( V_4 -> V_9 . V_10 ) ;
if ( V_5 == 0 )
return F_3 ( V_7 ) ;
V_7 = 1 ;
if ( V_5 & 0x02 ) {
F_4 ( V_4 -> V_9 . V_11 ) ;
if ( V_4 -> V_9 . V_12 )
V_4 -> V_9 . V_12 ( V_4 ) ;
}
if ( V_5 & 0x01 ) {
F_4 ( V_4 -> V_9 . V_13 ) ;
if ( V_4 -> V_9 . V_14 )
V_4 -> V_9 . V_14 ( V_4 ) ;
}
if ( V_5 & ( 0x20 | 0x40 ) ) {
unsigned int V_15 , V_16 ;
unsigned char V_17 , V_18 ;
struct V_19 * V_20 ;
V_15 = 0 ;
while ( ( ( V_17 = F_5 ( V_4 , V_21 ) ) & 0xc0 ) != 0xc0 ) {
V_18 = V_17 & 0x1f ;
V_16 = 1 << V_18 ;
if ( V_15 & V_16 )
continue;
V_15 |= V_16 ;
#if 0
printk(KERN_DEBUG "voice = %i, voice_status = 0x%x, "
"voice_verify = %i\n",
voice, voice_status, inb(GUSP(gus, GF1PAGE)));
#endif
V_20 = & V_4 -> V_9 . V_22 [ V_18 ] ;
if ( V_20 -> V_23 ) {
if ( ! ( V_17 & 0x80 ) ) {
F_4 ( V_20 -> V_24 ) ;
V_20 -> V_25 ( V_4 , V_20 ) ;
}
if ( ! ( V_17 & 0x40 ) ) {
F_4 ( V_20 -> V_26 ) ;
V_20 -> V_27 ( V_4 , V_20 ) ;
}
} else {
F_4 ( V_4 -> V_9 . V_28 ) ;
F_6 ( V_4 , V_29 ) ;
F_6 ( V_4 , V_30 ) ;
}
}
}
if ( V_5 & 0x04 ) {
F_4 ( V_4 -> V_9 . V_31 ) ;
if ( V_4 -> V_9 . V_32 )
V_4 -> V_9 . V_32 ( V_4 ) ;
}
if ( V_5 & 0x08 ) {
F_4 ( V_4 -> V_9 . V_33 ) ;
if ( V_4 -> V_9 . V_34 )
V_4 -> V_9 . V_34 ( V_4 ) ;
}
if ( V_5 & 0x80 ) {
if ( F_7 ( V_4 , V_35 ) & 0x40 ) {
F_4 ( V_4 -> V_9 . V_36 ) ;
if ( V_4 -> V_9 . V_37 )
V_4 -> V_9 . V_37 ( V_4 ) ;
}
if ( F_7 ( V_4 , V_38 ) & 0x40 ) {
F_4 ( V_4 -> V_9 . V_39 ) ;
if ( V_4 -> V_9 . V_40 )
V_4 -> V_9 . V_40 ( V_4 ) ;
}
}
if ( -- V_6 > 0 )
goto V_8;
return V_41 ;
}
static void F_8 ( struct V_42 * V_43 ,
struct V_44 * V_45 )
{
struct V_3 * V_4 ;
struct V_19 * V_20 ;
int V_46 ;
V_4 = V_43 -> V_47 ;
F_9 ( V_45 , L_1 , V_4 -> V_9 . V_13 ) ;
F_9 ( V_45 , L_2 , V_4 -> V_9 . V_11 ) ;
F_9 ( V_45 , L_3 , V_4 -> V_9 . V_31 ) ;
F_9 ( V_45 , L_4 , V_4 -> V_9 . V_33 ) ;
F_9 ( V_45 , L_5 , V_4 -> V_9 . V_36 ) ;
F_9 ( V_45 , L_6 , V_4 -> V_9 . V_39 ) ;
F_9 ( V_45 , L_7 , V_4 -> V_9 . V_28 ) ;
for ( V_46 = 0 ; V_46 < 32 ; V_46 ++ ) {
V_20 = & V_4 -> V_9 . V_22 [ V_46 ] ;
F_9 ( V_45 , L_8 ,
V_46 ,
V_20 -> V_24 ,
V_20 -> V_26 ) ;
}
}
void F_10 ( struct V_3 * V_4 )
{
struct V_42 * V_43 ;
if ( ! F_11 ( V_4 -> V_48 , L_9 , & V_43 ) )
F_12 ( V_43 , V_4 , F_8 ) ;
}
