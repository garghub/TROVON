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
V_17 -> V_18 |= V_19 ;
while ( ! F_9 () ) {
int V_20 ;
union {
T_1 V_21 [ 4 ] ;
T_2 V_22 ;
} V_23 ;
F_10 ( & V_24 ) ;
V_16 = F_11 ( V_25 , V_23 . V_21 ,
V_26 , 3 ) ;
if ( V_16 ) {
F_12 ( L_2 ,
V_16 ) ;
if ( ++ V_14 >= V_15 ) {
F_13 ( V_27 L_3
L_4 ,
V_28 ) ;
break;
}
F_14 ( & V_24 ) ;
continue;
}
V_23 . V_21 [ 3 ] = 0 ;
if ( V_23 . V_21 [ 2 ] & 0x10 )
V_23 . V_21 [ 2 ] |= 0x08 ;
for ( V_20 = 0 ; V_23 . V_22 ; V_23 . V_22 >>= 1 , V_20 ++ ) {
F_15 () ;
if ( V_23 . V_22 & 0x1 ) {
int V_29 = V_30 +
V_31 [ V_20 ] ;
F_16 ( V_29 ) ;
}
F_17 () ;
}
V_16 = F_18 ( V_25 , V_23 . V_21 ,
V_26 , 3 ) ;
if ( V_16 )
F_12 ( L_5 ) ;
F_7 ( V_13 ) ;
}
return 0 ;
}
static T_3 F_19 ( int V_13 , void * V_32 )
{
F_20 ( V_13 ) ;
F_14 ( V_32 ) ;
return V_33 ;
}
static inline void F_21 ( int V_13 )
{
#ifdef F_22
F_23 ( V_13 , V_34 ) ;
#else
F_24 ( V_13 ) ;
#endif
}
int F_25 ( struct V_35 * V_36 , unsigned int V_37 )
{
if ( V_37 )
F_26 ( & V_7 ) ;
else
F_27 ( & V_7 ) ;
return 0 ;
}
int F_28 ( T_1 V_38 , T_1 V_39 )
{
int V_16 ;
T_1 V_40 ;
V_16 = F_29 ( V_25 , & V_40 ,
V_26 + V_39 ) ;
V_40 &= ( ~ ( V_38 ) ) ;
V_16 |= F_30 ( V_25 , V_40 ,
V_26 + V_39 ) ;
return V_16 ;
}
int F_31 ( T_1 V_38 , T_1 V_39 )
{
int V_16 ;
T_1 V_41 ;
V_16 = F_29 ( V_25 , & V_41 ,
V_26 + V_39 ) ;
V_41 |= ( V_38 ) ;
V_16 |= F_30 ( V_25 , V_41 ,
V_26 + V_39 ) ;
return V_16 ;
}
int F_32 ( void )
{
int V_16 ;
T_1 V_42 = 0 ;
F_28 ( V_43 ,
V_44 ) ;
F_28 ( V_43 ,
V_45 ) ;
V_16 = F_29 ( V_46 , & V_42 , V_47 ) ;
if ( V_16 < 0 ) {
F_4 ( L_6 , V_16 ) ;
return V_16 ;
}
V_42 &= ~ V_48 ;
V_42 |= V_49 ;
V_16 = F_30 ( V_46 , V_42 , V_47 ) ;
if ( V_16 < 0 ) {
F_4 ( L_7 , V_16 ) ;
return V_16 ;
}
V_16 = F_29 ( V_46 , & V_42 ,
V_50 ) ;
if ( V_16 < 0 ) {
F_4 ( L_8 ,
V_16 ) ;
return V_16 ;
}
V_42 &= ~ ( V_51 | V_52 ) ;
V_16 = F_30 ( V_46 , V_42 ,
V_50 ) ;
if ( V_16 < 0 ) {
F_4 ( L_9 ,
V_16 ) ;
return V_16 ;
}
return 0 ;
}
int F_33 ( struct V_53 * V_54 , int V_55 )
{
int V_16 = - V_56 ;
T_1 V_57 = 0 ;
struct V_58 * V_59 = F_34 ( V_54 ) ;
if ( V_59 -> V_60 ) {
F_4 ( L_10 , V_59 -> V_60 , V_28 ) ;
return V_16 ;
}
V_16 = F_29 ( V_46 , & V_57 ,
V_47 ) ;
if ( V_16 >= 0 )
V_16 = V_57 & V_61 ;
return V_16 ;
}
int F_35 ( int V_62 , unsigned V_63 , unsigned V_64 )
{
int V_65 = 0 ;
int V_20 ;
struct V_66 * V_67 ;
int V_16 ;
T_1 V_68 [ 4 ] ;
static struct V_69 V_70 ;
V_68 [ 1 ] = 0xFF ;
V_68 [ 2 ] = 0xFF ;
V_68 [ 3 ] = 0xFF ;
V_16 = F_18 ( V_25 , & V_68 [ 0 ] ,
V_71 , 3 ) ;
V_16 = F_18 ( V_25 , & V_68 [ 0 ] ,
V_72 , 3 ) ;
V_16 = F_18 ( V_25 , & V_68 [ 0 ] ,
V_26 , 3 ) ;
V_30 = V_63 ;
V_70 = V_73 ;
V_70 . V_74 = L_11 ;
V_70 . V_75 = NULL ;
V_70 . V_76 = F_25 ;
for ( V_20 = V_63 ; V_20 < V_64 ; V_20 ++ ) {
F_36 ( V_20 , & V_70 ,
V_77 ) ;
F_37 ( V_20 , ( void * ) V_62 ) ;
F_21 ( V_20 ) ;
}
V_78 = V_20 ;
F_38 ( L_12 , L_13 ,
V_62 , V_63 , V_78 - 1 ) ;
F_39 ( & V_24 ) ;
V_65 = F_40 ( V_62 , F_19 , 0 ,
L_14 , & V_24 ) ;
if ( V_65 < 0 ) {
F_4 ( L_15 , V_62 , V_65 ) ;
goto V_79;
}
V_67 = F_41 ( F_8 , ( void * ) V_62 , L_16 ) ;
if ( F_42 ( V_67 ) ) {
F_4 ( L_17 , V_62 ) ;
V_65 = F_43 ( V_67 ) ;
goto V_80;
}
V_9 = V_62 ;
F_44 ( & V_81 ) ;
return V_65 ;
V_80:
F_45 ( V_62 , & V_24 ) ;
V_79:
for ( V_20 = V_63 ; V_20 < V_64 ; V_20 ++ )
F_36 ( V_20 , NULL , NULL ) ;
return V_65 ;
}
int F_46 ( void )
{
F_47 ( & V_81 ) ;
if ( V_30 ) {
F_4 ( L_18 ) ;
return - V_82 ;
}
return 0 ;
}
