static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
if ( ! V_5 -> V_8 || V_5 -> V_8 () )
V_7 = & V_5 -> V_9 ;
else
V_7 = & V_5 -> V_10 ;
F_3 ( & V_7 -> V_2 , V_2 ) ;
return V_11 . V_12 ( & V_7 -> V_2 , V_3 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 -> V_8 )
return 0 ;
return V_5 -> V_8 () ? 0 : 1 ;
}
void T_2 F_5 ( int V_13 , const char * V_14 ,
const char * V_15 , struct V_16 * V_16 )
{
if ( ! F_6 ( V_16 ) && ( V_13 != V_17 ) )
V_18 [ V_13 ] = V_16 ;
if ( ! F_6 ( V_16 ) )
F_7 ( V_16 , V_14 , V_15 ) ;
}
int T_2 F_8 ( const struct V_19 * V_20 , int V_21 )
{
int V_22 ;
struct V_4 * V_4 ;
struct V_16 * V_16 ;
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ ) {
V_4 = F_9 ( sizeof( * V_4 ) , V_23 ) ;
V_4 -> V_8 = V_20 [ V_22 ] . V_8 ;
V_4 -> V_9 = V_20 [ V_22 ] . V_9 ;
V_4 -> V_10 = V_20 [ V_22 ] . V_10 ;
V_4 -> V_24 = V_20 [ V_22 ] . V_24 ;
V_4 -> V_24 . V_25 = & V_26 ;
V_16 = F_10 ( NULL , V_20 [ V_22 ] . V_27 ,
V_20 [ V_22 ] . V_28 , 2 ,
& V_4 -> V_2 , & V_29 ,
& V_4 -> V_2 , & V_30 ,
& V_4 -> V_24 . V_2 , & V_31 ,
V_20 [ V_22 ] . V_32 ) ;
F_5 ( V_20 [ V_22 ] . V_13 , V_20 [ V_22 ] . V_14 ,
V_20 [ V_22 ] . V_15 , V_16 ) ;
}
return 0 ;
}
void T_2 F_11 ( struct V_33 * V_34 )
{
F_12 ( V_34 , V_35 , & V_36 ) ;
}
void F_13 ( bool V_37 )
{
unsigned long V_32 ;
unsigned int V_38 , V_39 ;
F_14 ( V_32 ) ;
asm("mrc p14, 0, %0, c6, c0, 0" : "=r" (clkcfg));
V_39 &= ~ V_40 & ~ V_41 ;
if ( V_37 )
V_39 |= V_40 ;
V_39 |= V_42 ;
asm volatile(
" b 2f\n"
" .align 5\n"
"1: mcr p14, 0, %1, c6, c0, 0\n"
" b 3f\n"
"2: b 1b\n"
"3: nop\n"
: "=&r" (unused)
: "r" (clkcfg)
: );
F_15 ( V_32 ) ;
}
void F_16 ( struct V_43 * V_44 ,
T_3 (* F_17)( unsigned int ) , void T_4 * V_45 ,
void T_4 * V_46 )
{
unsigned int V_39 = V_44 -> V_39 ;
unsigned int V_38 , V_47 , V_48 ;
unsigned long V_32 ;
F_14 ( V_32 ) ;
V_47 = V_48 = F_18 ( V_45 ) ;
if ( ( V_47 & V_49 ) > F_17 ( V_44 -> V_50 ) ) {
V_47 = ( V_47 & ~ V_49 ) ;
V_47 |= F_17 ( V_44 -> V_50 ) ;
}
V_48 =
( V_48 & ~ V_49 ) |
F_17 ( V_44 -> V_50 ) ;
if ( V_44 -> V_51 ) {
V_47 |= V_52 ;
V_48 |= V_52 ;
} else {
V_48 &= ~ V_52 ;
}
F_19 ( V_44 -> V_46 , V_46 ) ;
asm volatile(
" ldr r4, [%1]\n"
" b 2f\n"
" .align 5\n"
"1: str %3, [%1] /* preset the MDREFR */\n"
" mcr p14, 0, %2, c6, c0, 0 /* set CLKCFG[FCS] */\n"
" str %4, [%1] /* postset the MDREFR */\n"
" b 3f\n"
"2: b 1b\n"
"3: nop\n"
: "=&r" (unused)
: "r" (mdrefr), "r" (clkcfg), "r" (preset_mdrefr),
"r" (postset_mdrefr)
: "r4", "r5");
F_15 ( V_32 ) ;
}
int F_20 ( struct V_53 * V_54 ,
struct V_43 * V_55 , int V_56 )
{
int V_22 , V_57 = - 1 , V_58 = - 1 ;
unsigned long V_59 ;
for ( V_22 = 0 ; V_22 < V_56 ; V_22 ++ ) {
V_59 = V_55 [ V_22 ] . V_60 ;
if ( V_59 == V_54 -> V_59 )
break;
if ( V_59 < V_54 -> V_61 )
continue;
if ( V_59 > V_54 -> V_62 )
continue;
if ( V_59 <= V_54 -> V_59 )
V_57 = V_22 ;
if ( ( V_59 >= V_54 -> V_59 ) && ( V_58 == - 1 ) )
V_58 = V_22 ;
}
V_54 -> V_63 = NULL ;
if ( V_22 < V_56 ) {
V_59 = V_54 -> V_59 ;
} else if ( V_57 >= 0 ) {
V_59 = V_55 [ V_57 ] . V_60 ;
} else if ( V_58 >= 0 ) {
V_59 = V_55 [ V_58 ] . V_60 ;
} else {
F_21 ( L_1 , V_64 , V_54 -> V_59 ) ;
return - V_65 ;
}
F_21 ( L_2 , V_64 , V_54 -> V_59 , V_59 ) ;
V_54 -> V_59 = V_59 ;
return 0 ;
}
