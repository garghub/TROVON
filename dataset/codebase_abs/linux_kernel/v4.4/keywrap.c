static inline void F_1 ( T_1 V_1 , T_2 * V_2 )
{
T_3 * V_3 = ( T_3 * ) V_2 ;
* V_3 = F_2 ( V_1 ) ;
}
static void F_3 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
unsigned int V_8 )
{
unsigned int V_9 = 0 ;
F_4 ( V_8 < V_10 ) ;
V_9 = V_8 - V_10 ;
while ( V_7 ) {
if ( V_7 -> V_11 > V_9 ) {
F_5 ( V_5 , V_7 ) ;
F_6 ( V_5 , V_9 ) ;
break;
} else
V_9 -= V_7 -> V_11 ;
V_7 = F_7 ( V_7 ) ;
}
}
static int F_8 ( struct V_12 * V_13 ,
struct V_6 * V_14 , struct V_6 * V_15 ,
unsigned int V_16 )
{
struct V_17 * V_18 = V_13 -> V_18 ;
struct V_19 * V_20 = F_9 ( V_18 ) ;
struct V_21 * V_22 = V_20 -> V_22 ;
unsigned long V_23 = F_10 (unsigned long, SEMIBSIZE,
crypto_cipher_alignmask(child)) ;
unsigned int V_24 ;
T_2 V_25 [ sizeof( struct V_26 ) + V_23 ] ;
struct V_26 * V_27 = (struct V_26 * )
F_11 ( V_25 + 0 , V_23 + 1 ) ;
T_1 V_28 = 6 * ( ( V_16 ) >> 3 ) ;
struct V_6 * V_29 , * V_30 ;
int V_31 = 0 ;
if ( V_16 < ( 2 * V_10 ) || V_16 % V_10 )
return - V_32 ;
memcpy ( V_27 -> V_33 , V_13 -> V_34 , V_10 ) ;
V_29 = V_15 ;
V_30 = V_14 ;
for ( V_24 = 0 ; V_24 < 6 ; V_24 ++ ) {
T_2 V_35 [ V_10 + V_23 ] ;
T_2 * V_36 = F_11 ( V_35 + 0 , V_23 + 1 ) ;
unsigned int V_37 = V_16 ;
struct V_4 V_38 , V_39 ;
while ( V_37 ) {
F_3 ( & V_38 , V_29 , V_37 ) ;
F_12 ( V_27 -> V_40 , & V_38 , V_10 ,
false ) ;
F_1 ( V_28 , V_36 ) ;
F_13 ( V_27 -> V_33 , V_36 , V_10 ) ;
V_28 -- ;
F_14 ( V_22 , ( T_2 * ) V_27 ,
( T_2 * ) V_27 ) ;
F_3 ( & V_39 , V_30 , V_37 ) ;
F_12 ( V_27 -> V_40 , & V_39 , V_10 ,
true ) ;
V_37 -= V_10 ;
}
V_29 = V_14 ;
V_30 = V_14 ;
}
if ( F_15 ( L_1 , V_27 -> V_33 ,
V_10 ) )
V_31 = - V_41 ;
F_16 ( & V_27 , sizeof( struct V_26 ) ) ;
return V_31 ;
}
static int F_17 ( struct V_12 * V_13 ,
struct V_6 * V_14 , struct V_6 * V_15 ,
unsigned int V_16 )
{
struct V_17 * V_18 = V_13 -> V_18 ;
struct V_19 * V_20 = F_9 ( V_18 ) ;
struct V_21 * V_22 = V_20 -> V_22 ;
unsigned long V_23 = F_10 (unsigned long, SEMIBSIZE,
crypto_cipher_alignmask(child)) ;
unsigned int V_24 ;
T_2 V_25 [ sizeof( struct V_26 ) + V_23 ] ;
struct V_26 * V_27 = (struct V_26 * )
F_11 ( V_25 + 0 , V_23 + 1 ) ;
T_1 V_28 = 1 ;
struct V_6 * V_29 , * V_30 ;
if ( V_16 < ( 2 * V_10 ) || V_16 % V_10 )
return - V_32 ;
memcpy ( V_27 -> V_33 , L_1 , V_10 ) ;
V_29 = V_15 ;
V_30 = V_14 ;
for ( V_24 = 0 ; V_24 < 6 ; V_24 ++ ) {
T_2 V_35 [ V_10 + V_23 ] ;
T_2 * V_36 = F_11 ( V_35 + 0 , V_23 + 1 ) ;
unsigned int V_37 = V_16 ;
struct V_4 V_38 , V_39 ;
F_5 ( & V_38 , V_29 ) ;
F_5 ( & V_39 , V_30 ) ;
while ( V_37 ) {
F_12 ( V_27 -> V_40 , & V_38 , V_10 ,
false ) ;
F_18 ( V_22 , ( T_2 * ) V_27 ,
( T_2 * ) V_27 ) ;
F_1 ( V_28 , V_36 ) ;
F_13 ( V_27 -> V_33 , V_36 , V_10 ) ;
V_28 ++ ;
F_12 ( V_27 -> V_40 , & V_39 , V_10 ,
true ) ;
V_37 -= V_10 ;
}
V_29 = V_14 ;
V_30 = V_14 ;
}
memcpy ( V_13 -> V_34 , V_27 -> V_33 , V_10 ) ;
F_16 ( & V_27 , sizeof( struct V_26 ) ) ;
return 0 ;
}
static int F_19 ( struct V_42 * V_43 , const T_2 * V_44 ,
unsigned int V_45 )
{
struct V_19 * V_20 = F_20 ( V_43 ) ;
struct V_21 * V_22 = V_20 -> V_22 ;
int V_46 ;
F_21 ( V_22 , V_47 ) ;
F_22 ( V_22 , F_23 ( V_43 ) &
V_47 ) ;
V_46 = F_24 ( V_22 , V_44 , V_45 ) ;
F_25 ( V_43 , F_26 ( V_22 ) &
V_48 ) ;
return V_46 ;
}
static int F_27 ( struct V_42 * V_18 )
{
struct V_49 * V_50 = F_28 ( V_18 ) ;
struct V_51 * V_52 = F_29 ( V_50 ) ;
struct V_19 * V_20 = F_20 ( V_18 ) ;
struct V_21 * V_53 ;
V_53 = F_30 ( V_52 ) ;
if ( F_31 ( V_53 ) )
return F_32 ( V_53 ) ;
V_20 -> V_22 = V_53 ;
return 0 ;
}
static void F_33 ( struct V_42 * V_18 )
{
struct V_19 * V_20 = F_20 ( V_18 ) ;
F_34 ( V_20 -> V_22 ) ;
}
static struct V_49 * F_35 ( struct V_54 * * V_55 )
{
struct V_49 * V_50 = NULL ;
struct V_56 * V_57 = NULL ;
int V_46 ;
V_46 = F_36 ( V_55 , V_58 ) ;
if ( V_46 )
return F_37 ( V_46 ) ;
V_57 = F_38 ( V_55 , V_59 ,
V_60 ) ;
if ( F_31 ( V_57 ) )
return F_39 ( V_57 ) ;
V_50 = F_37 ( - V_32 ) ;
if ( V_57 -> V_61 != sizeof( struct V_26 ) )
goto V_46;
V_50 = F_40 ( L_2 , V_57 ) ;
if ( F_31 ( V_50 ) )
goto V_46;
V_50 -> V_57 . V_62 = V_58 ;
V_50 -> V_57 . V_63 = V_57 -> V_63 ;
V_50 -> V_57 . V_61 = V_10 ;
V_50 -> V_57 . V_64 = 0 ;
V_50 -> V_57 . V_65 = & V_66 ;
V_50 -> V_57 . V_67 . V_68 = V_10 ;
V_50 -> V_57 . V_67 . V_69 = V_57 -> V_70 . V_71 ;
V_50 -> V_57 . V_67 . V_72 = V_57 -> V_70 . V_73 ;
V_50 -> V_57 . V_74 = sizeof( struct V_19 ) ;
V_50 -> V_57 . V_75 = F_27 ;
V_50 -> V_57 . V_76 = F_33 ;
V_50 -> V_57 . V_67 . V_77 = F_19 ;
V_50 -> V_57 . V_67 . V_78 = F_17 ;
V_50 -> V_57 . V_67 . V_79 = F_8 ;
V_46:
F_41 ( V_57 ) ;
return V_50 ;
}
static void F_42 ( struct V_49 * V_50 )
{
F_43 ( F_29 ( V_50 ) ) ;
F_44 ( V_50 ) ;
}
static int T_4 F_45 ( void )
{
return F_46 ( & V_80 ) ;
}
static void T_5 F_47 ( void )
{
F_48 ( & V_80 ) ;
}
