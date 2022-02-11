static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
int V_5 ;
switch ( V_3 ) {
case V_6 :
V_5 = F_2 ( & V_7 ) ;
if ( V_5 && ! V_8 ) {
if ( F_3 ( V_9 ) )
F_4 ( L_1 ) ;
else
V_8 = true ;
} else if ( ! V_5 && V_8 ) {
F_5 ( V_9 ) ;
V_8 = false ;
}
F_6 ( V_9 ) ;
break;
case V_10 :
F_7 ( V_9 ) ;
break;
default:
break;
}
return V_11 ;
}
static int F_8 ( void * V_12 )
{
long V_13 = ( long ) V_12 ;
static unsigned V_14 ;
static const unsigned V_15 = 100 ;
int V_16 ;
while ( ! F_9 () ) {
int V_17 ;
union {
T_1 V_18 [ 4 ] ;
T_2 V_19 ;
} V_20 ;
F_10 ( & V_21 ) ;
V_16 = F_11 ( V_22 , V_20 . V_18 ,
V_23 , 3 ) ;
if ( V_16 ) {
F_12 ( L_2 ,
V_16 ) ;
if ( ++ V_14 >= V_15 ) {
F_13 ( V_24 L_3
L_4 ,
V_25 ) ;
break;
}
F_14 ( & V_21 ) ;
continue;
}
V_20 . V_18 [ 3 ] = 0 ;
if ( V_20 . V_18 [ 2 ] & 0x10 )
V_20 . V_18 [ 2 ] |= 0x08 ;
for ( V_17 = 0 ; V_20 . V_19 ; V_20 . V_19 >>= 1 , V_17 ++ ) {
F_15 () ;
if ( V_20 . V_19 & 0x1 ) {
int V_26 = V_27 +
V_28 [ V_17 ] ;
F_16 ( V_26 ) ;
}
F_17 () ;
}
V_16 = F_18 ( V_22 , 0x00 , V_23 ) ;
if ( V_16 )
F_12 ( L_5 ) ;
F_7 ( V_13 ) ;
}
return 0 ;
}
static T_3 F_19 ( int V_13 , void * V_29 )
{
F_20 ( V_13 ) ;
F_14 ( V_29 ) ;
return V_30 ;
}
static inline void F_21 ( int V_13 )
{
#ifdef F_22
F_23 ( V_13 , V_31 ) ;
#else
F_24 ( V_13 ) ;
#endif
}
static int F_25 ( struct V_32 * V_33 , unsigned int V_34 )
{
if ( V_34 )
F_26 ( & V_7 ) ;
else
F_27 ( & V_7 ) ;
return 0 ;
}
int F_28 ( T_1 V_35 , T_1 V_36 )
{
int V_16 ;
T_1 V_37 ;
V_16 = F_29 ( V_22 , & V_37 ,
V_23 + V_36 ) ;
V_37 &= ( ~ ( V_35 ) ) ;
V_16 |= F_18 ( V_22 , V_37 ,
V_23 + V_36 ) ;
return V_16 ;
}
int F_30 ( T_1 V_35 , T_1 V_36 )
{
int V_16 ;
T_1 V_38 ;
V_16 = F_29 ( V_22 , & V_38 ,
V_23 + V_36 ) ;
V_38 |= ( V_35 ) ;
V_16 |= F_18 ( V_22 , V_38 ,
V_23 + V_36 ) ;
return V_16 ;
}
int F_31 ( void )
{
int V_16 ;
T_1 V_39 = 0 ;
F_28 ( V_40 ,
V_41 ) ;
F_28 ( V_40 ,
V_42 ) ;
V_16 = F_29 ( V_43 , & V_39 , V_44 ) ;
if ( V_16 < 0 ) {
F_4 ( L_6 , V_16 ) ;
return V_16 ;
}
V_39 &= ~ V_45 ;
V_39 |= V_46 ;
V_16 = F_18 ( V_43 , V_39 , V_44 ) ;
if ( V_16 < 0 ) {
F_4 ( L_7 , V_16 ) ;
return V_16 ;
}
V_16 = F_29 ( V_43 , & V_39 ,
V_47 ) ;
if ( V_16 < 0 ) {
F_4 ( L_8 ,
V_16 ) ;
return V_16 ;
}
V_39 &= ~ ( V_48 | V_49 ) ;
V_16 = F_18 ( V_43 , V_39 ,
V_47 ) ;
if ( V_16 < 0 ) {
F_4 ( L_9 ,
V_16 ) ;
return V_16 ;
}
return V_27 + V_50 ;
}
int F_32 ( struct V_51 * V_52 , int V_53 )
{
int V_16 = - V_54 ;
T_1 V_55 = 0 ;
struct V_56 * V_57 = F_33 ( V_52 ) ;
if ( V_57 -> V_58 ) {
F_4 ( L_10 , V_57 -> V_58 , V_25 ) ;
return V_16 ;
}
V_16 = F_29 ( V_43 , & V_55 ,
V_44 ) ;
if ( V_16 >= 0 )
V_16 = V_55 & V_59 ;
return V_16 ;
}
int F_34 ( struct V_51 * V_52 , int V_60 )
{
struct V_61 * V_62 = V_52 -> V_63 ;
int V_64 , V_65 , V_66 ;
struct V_67 * V_68 ;
static struct V_69 V_70 ;
int V_71 = 0 ;
int V_17 ;
T_1 V_72 [ 3 ] ;
V_64 = V_73 ;
V_65 = F_35 ( - 1 , 0 , V_64 , 0 ) ;
if ( F_36 ( V_65 ) ) {
F_37 ( V_52 , L_11 ) ;
return V_65 ;
}
F_38 ( V_62 , V_64 , V_65 , 0 ,
& V_74 , NULL ) ;
V_66 = V_65 + V_64 ;
V_72 [ 0 ] = 0xFF ;
V_72 [ 1 ] = 0xFF ;
V_72 [ 2 ] = 0xFF ;
F_39 ( V_22 , & V_72 [ 0 ] , V_75 , 3 ) ;
F_39 ( V_22 , & V_72 [ 0 ] , V_76 , 3 ) ;
F_39 ( V_22 , & V_72 [ 0 ] , V_23 , 3 ) ;
V_27 = V_65 ;
V_70 = V_77 ;
V_70 . V_78 = L_12 ;
V_70 . V_79 = NULL ;
V_70 . V_80 = F_25 ;
for ( V_17 = V_65 ; V_17 < V_66 ; V_17 ++ ) {
F_40 ( V_17 , & V_70 ,
V_81 ) ;
F_41 ( V_17 , ( void * ) V_60 ) ;
F_21 ( V_17 ) ;
}
F_42 ( V_52 , L_13 ,
V_60 , V_65 , V_66 ) ;
F_43 ( & V_21 ) ;
V_71 = F_44 ( V_60 , F_19 , 0 , L_14 ,
& V_21 ) ;
if ( V_71 < 0 ) {
F_37 ( V_52 , L_15 , V_60 , V_71 ) ;
goto V_82;
}
V_68 = F_45 ( F_8 , ( void * ) V_60 , L_16 ) ;
if ( F_46 ( V_68 ) ) {
F_37 ( V_52 , L_17 , V_60 ) ;
V_71 = F_47 ( V_68 ) ;
goto V_83;
}
V_9 = V_60 ;
F_48 ( & V_84 ) ;
return V_65 ;
V_83:
F_49 ( V_60 , & V_21 ) ;
V_82:
for ( V_17 = V_65 ; V_17 < V_66 ; V_17 ++ )
F_40 ( V_17 , NULL , NULL ) ;
return V_71 ;
}
int F_50 ( void )
{
F_51 ( & V_84 ) ;
if ( V_27 ) {
F_4 ( L_18 ) ;
return - V_85 ;
}
return 0 ;
}
