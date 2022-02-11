static void F_1 ( unsigned int V_1 ,
unsigned int V_2 ,
T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_6 + V_3 ) ;
T_2 V_7 = F_3 ( & V_8 -> V_7 [ V_1 ] ) ;
unsigned int V_9 = ( V_7 >> 4 ) & 3 ;
unsigned int clock = V_2 / ( 4 - V_9 ) ;
unsigned int V_10 = 1000000000 / clock ;
unsigned int V_11 ;
int V_12 ;
V_12 = F_4 ( V_5 -> V_13 , V_10 ) - 2 ;
V_12 = F_5 ( int , V_12 , F_4 ( 35 , V_10 ) ) ;
if ( V_12 > 2 && ( V_12 & 1 ) )
V_12 ++ ;
V_12 &= ~ 1 ;
V_11 = F_4 ( V_5 -> V_14 , V_10 ) ;
while ( ( V_11 * 4 + V_12 + ( V_12 ? 2 : 3 ) ) * V_10 < V_5 -> V_10 )
V_11 ++ ;
if ( V_11 > 7 ) {
F_6 ( L_1 , V_11 ) ;
V_11 = 7 ;
}
F_7 ( L_2 ,
V_1 , V_10 , V_12 , V_11 ) ;
F_8 ( ( V_7 & ~ 0x3f007ull ) | ( V_12 << 12 ) | V_11 ,
& V_8 -> V_7 [ V_1 ] ) ;
}
static void F_9 ( T_3 * V_15 , T_4 * V_16 )
{
struct V_17 * V_18 = V_15 -> V_19 -> V_20 ;
T_1 V_21 = V_16 -> V_22 - V_6 ;
T_4 * V_23 ;
V_23 = F_10 ( V_16 ) ;
if ( V_23 )
V_21 = F_11 ( T_1 , V_21 , V_23 -> V_22 - V_6 ) ;
F_1 ( V_18 -> V_1 , V_18 -> V_2 , V_21 ) ;
}
static void F_12 ( T_4 * V_16 , struct V_24 * V_25 ,
void * V_26 , unsigned int V_27 )
{
unsigned long V_28 = V_16 -> V_15 -> V_29 . V_30 ;
unsigned short * V_31 = V_26 ;
unsigned int V_32 = ( V_27 + 1 ) / 2 ;
while ( V_32 -- )
* V_31 ++ = F_13 ( F_14 ( ( void V_33 * ) V_28 ) ) ;
F_15 ( ( unsigned long ) V_26 , F_16 ( V_27 , 2 ) ) ;
}
static void F_17 ( T_4 * V_16 , struct V_24 * V_25 ,
void * V_26 , unsigned int V_27 )
{
unsigned long V_28 = V_16 -> V_15 -> V_29 . V_30 ;
unsigned short * V_31 = V_26 ;
unsigned int V_32 = ( V_27 + 1 ) / 2 ;
while ( V_32 -- ) {
F_18 ( F_19 ( * V_31 ) , ( void V_33 * ) V_28 ) ;
V_31 ++ ;
}
F_15 ( ( unsigned long ) V_26 , F_16 ( V_27 , 2 ) ) ;
}
static int T_5 F_20 ( struct V_34 * V_35 )
{
struct V_36 V_37 , * V_38 [] = { & V_37 } ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
struct V_17 * V_18 = V_35 -> V_19 . V_20 ;
int V_43 , V_44 , V_45 ;
unsigned long V_46 , V_47 ;
struct V_48 V_49 = V_50 ;
V_43 = F_21 ( V_35 , 0 ) ;
if ( V_43 < 0 )
return - V_51 ;
V_42 = F_22 ( V_35 , V_52 , 0 ) ;
if ( ! V_42 )
return - V_51 ;
if ( ! F_23 ( & V_35 -> V_19 , V_42 -> V_53 ,
F_24 ( V_42 ) , L_3 ) )
return - V_54 ;
V_46 = ( unsigned long ) F_25 ( & V_35 -> V_19 , V_42 -> V_53 ,
8 << V_18 -> V_55 ) ;
V_47 = ( unsigned long ) F_25 ( & V_35 -> V_19 ,
V_42 -> V_53 + 0x10000 +
( 6 << V_18 -> V_55 ) ,
1 << V_18 -> V_55 ) ;
if ( ! V_46 || ! V_47 )
return - V_54 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
if ( V_18 -> V_55 ) {
unsigned long V_28 = V_46 ;
unsigned long V_56 = V_47 ;
V_37 . V_57 [ 0 ] = V_28 ;
#ifdef F_26
V_28 ++ ;
V_56 ++ ;
#endif
for ( V_45 = 1 ; V_45 <= 7 ; V_45 ++ )
V_37 . V_57 [ V_45 ] =
V_28 + ( V_45 << V_18 -> V_55 ) ;
V_37 . V_29 . V_58 = V_56 ;
} else
F_27 ( & V_37 , V_46 , V_47 ) ;
V_37 . V_43 = V_43 ;
V_37 . V_19 = & V_35 -> V_19 ;
F_28 ( L_4 ,
V_46 , V_47 , V_37 . V_43 ) ;
if ( V_18 -> V_2 )
F_1 ( V_18 -> V_1 , V_18 -> V_2 , 0 ) ;
else
V_49 . V_59 = NULL ;
V_44 = F_29 ( & V_49 , V_38 , 1 , & V_40 ) ;
if ( ! V_44 )
F_30 ( V_35 , V_40 ) ;
return V_44 ;
}
static int T_6 F_31 ( struct V_34 * V_35 )
{
struct V_39 * V_40 = F_32 ( V_35 ) ;
F_33 ( V_40 ) ;
return 0 ;
}
