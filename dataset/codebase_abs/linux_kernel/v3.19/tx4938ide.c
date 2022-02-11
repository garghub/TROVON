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
struct V_17 * V_18 = F_10 ( V_15 -> V_19 ) ;
T_1 V_20 = V_16 -> V_21 - V_6 ;
T_4 * V_22 ;
V_22 = F_11 ( V_16 ) ;
if ( V_22 )
V_20 = F_12 ( T_1 , V_20 , V_22 -> V_21 - V_6 ) ;
F_1 ( V_18 -> V_1 , V_18 -> V_2 , V_20 ) ;
}
static void F_13 ( T_4 * V_16 , struct V_23 * V_24 ,
void * V_25 , unsigned int V_26 )
{
unsigned long V_27 = V_16 -> V_15 -> V_28 . V_29 ;
unsigned short * V_30 = V_25 ;
unsigned int V_31 = ( V_26 + 1 ) / 2 ;
while ( V_31 -- )
* V_30 ++ = F_14 ( F_15 ( ( void V_32 * ) V_27 ) ) ;
F_16 ( ( unsigned long ) V_25 , F_17 ( V_26 , 2 ) ) ;
}
static void F_18 ( T_4 * V_16 , struct V_23 * V_24 ,
void * V_25 , unsigned int V_26 )
{
unsigned long V_27 = V_16 -> V_15 -> V_28 . V_29 ;
unsigned short * V_30 = V_25 ;
unsigned int V_31 = ( V_26 + 1 ) / 2 ;
while ( V_31 -- ) {
F_19 ( F_20 ( * V_30 ) , ( void V_32 * ) V_27 ) ;
V_30 ++ ;
}
F_16 ( ( unsigned long ) V_25 , F_17 ( V_26 , 2 ) ) ;
}
static int T_5 F_21 ( struct V_33 * V_34 )
{
struct V_35 V_36 , * V_37 [] = { & V_36 } ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
struct V_17 * V_18 = F_10 ( & V_34 -> V_19 ) ;
int V_42 , V_43 , V_44 ;
unsigned long V_45 , V_46 ;
struct V_47 V_48 = V_49 ;
V_42 = F_22 ( V_34 , 0 ) ;
if ( V_42 < 0 )
return - V_50 ;
V_41 = F_23 ( V_34 , V_51 , 0 ) ;
if ( ! V_41 )
return - V_50 ;
if ( ! F_24 ( & V_34 -> V_19 , V_41 -> V_52 ,
F_25 ( V_41 ) , L_3 ) )
return - V_53 ;
V_45 = ( unsigned long ) F_26 ( & V_34 -> V_19 , V_41 -> V_52 ,
8 << V_18 -> V_54 ) ;
V_46 = ( unsigned long ) F_26 ( & V_34 -> V_19 ,
V_41 -> V_52 + 0x10000 +
( 6 << V_18 -> V_54 ) ,
1 << V_18 -> V_54 ) ;
if ( ! V_45 || ! V_46 )
return - V_53 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
if ( V_18 -> V_54 ) {
unsigned long V_27 = V_45 ;
unsigned long V_55 = V_46 ;
V_36 . V_56 [ 0 ] = V_27 ;
#ifdef F_27
V_27 ++ ;
V_55 ++ ;
#endif
for ( V_44 = 1 ; V_44 <= 7 ; V_44 ++ )
V_36 . V_56 [ V_44 ] =
V_27 + ( V_44 << V_18 -> V_54 ) ;
V_36 . V_28 . V_57 = V_55 ;
} else
F_28 ( & V_36 , V_45 , V_46 ) ;
V_36 . V_42 = V_42 ;
V_36 . V_19 = & V_34 -> V_19 ;
F_29 ( L_4 ,
V_45 , V_46 , V_36 . V_42 ) ;
if ( V_18 -> V_2 )
F_1 ( V_18 -> V_1 , V_18 -> V_2 , 0 ) ;
else
V_48 . V_58 = NULL ;
V_43 = F_30 ( & V_48 , V_37 , 1 , & V_39 ) ;
if ( ! V_43 )
F_31 ( V_34 , V_39 ) ;
return V_43 ;
}
static int T_6 F_32 ( struct V_33 * V_34 )
{
struct V_38 * V_39 = F_33 ( V_34 ) ;
F_34 ( V_39 ) ;
return 0 ;
}
