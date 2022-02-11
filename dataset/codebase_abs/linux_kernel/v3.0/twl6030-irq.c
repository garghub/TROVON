static int F_1 ( void * V_1 )
{
long V_2 = ( long ) V_1 ;
static unsigned V_3 ;
static const unsigned V_4 = 100 ;
int V_5 ;
V_6 -> V_7 |= V_8 ;
while ( ! F_2 () ) {
int V_9 ;
union {
T_1 V_10 [ 4 ] ;
T_2 V_11 ;
} V_12 ;
F_3 ( & V_13 ) ;
V_5 = F_4 ( V_14 , V_12 . V_10 ,
V_15 , 3 ) ;
if ( V_5 ) {
F_5 ( L_1 ,
V_5 ) ;
if ( ++ V_3 >= V_4 ) {
F_6 ( V_16 L_2
L_3 ,
V_17 ) ;
break;
}
F_7 ( & V_13 ) ;
continue;
}
V_12 . V_10 [ 3 ] = 0 ;
if ( V_12 . V_10 [ 2 ] & 0x10 )
V_12 . V_10 [ 2 ] |= 0x08 ;
for ( V_9 = 0 ; V_12 . V_11 ; V_12 . V_11 >>= 1 , V_9 ++ ) {
F_8 () ;
if ( V_12 . V_11 & 0x1 ) {
int V_18 = V_19 +
V_20 [ V_9 ] ;
F_9 ( V_18 ) ;
}
F_10 () ;
}
V_5 = F_11 ( V_14 , V_12 . V_10 ,
V_15 , 3 ) ;
if ( V_5 )
F_5 ( L_4 ) ;
F_12 ( V_2 ) ;
}
return 0 ;
}
static T_3 F_13 ( int V_2 , void * V_21 )
{
F_14 ( V_2 ) ;
F_7 ( V_21 ) ;
return V_22 ;
}
static inline void F_15 ( int V_2 )
{
#ifdef F_16
F_17 ( V_2 , V_23 ) ;
#else
F_18 ( V_2 ) ;
#endif
}
int F_19 ( T_1 V_24 , T_1 V_25 )
{
int V_5 ;
T_1 V_26 ;
V_5 = F_20 ( V_14 , & V_26 ,
V_15 + V_25 ) ;
V_26 &= ( ~ ( V_24 ) ) ;
V_5 |= F_21 ( V_14 , V_26 ,
V_15 + V_25 ) ;
return V_5 ;
}
int F_22 ( T_1 V_24 , T_1 V_25 )
{
int V_5 ;
T_1 V_27 ;
V_5 = F_20 ( V_14 , & V_27 ,
V_15 + V_25 ) ;
V_27 |= ( V_24 ) ;
V_5 |= F_21 ( V_14 , V_27 ,
V_15 + V_25 ) ;
return V_5 ;
}
int F_23 ( void )
{
int V_5 ;
T_1 V_28 = 0 ;
F_19 ( V_29 ,
V_30 ) ;
F_19 ( V_29 ,
V_31 ) ;
V_5 = F_20 ( V_32 , & V_28 , V_33 ) ;
if ( V_5 < 0 ) {
F_24 ( L_5 , V_5 ) ;
return V_5 ;
}
V_28 &= ~ V_34 ;
V_28 |= V_35 ;
V_5 = F_21 ( V_32 , V_28 , V_33 ) ;
if ( V_5 < 0 ) {
F_24 ( L_6 , V_5 ) ;
return V_5 ;
}
V_5 = F_20 ( V_32 , & V_28 ,
V_36 ) ;
if ( V_5 < 0 ) {
F_24 ( L_7 ,
V_5 ) ;
return V_5 ;
}
V_28 &= ~ ( V_37 | V_38 ) ;
V_5 = F_21 ( V_32 , V_28 ,
V_36 ) ;
if ( V_5 < 0 ) {
F_24 ( L_8 ,
V_5 ) ;
return V_5 ;
}
return 0 ;
}
int F_25 ( struct V_39 * V_40 , int V_41 )
{
int V_5 = - V_42 ;
T_1 V_43 = 0 ;
struct V_44 * V_45 = F_26 ( V_40 ) ;
if ( V_45 -> V_46 ) {
F_24 ( L_9 , V_45 -> V_46 , V_17 ) ;
return V_5 ;
}
V_5 = F_20 ( V_32 , & V_43 ,
V_33 ) ;
if ( V_5 >= 0 )
V_5 = V_43 & V_47 ;
return V_5 ;
}
int F_27 ( int V_48 , unsigned V_49 , unsigned V_50 )
{
int V_51 = 0 ;
int V_9 ;
struct V_52 * V_53 ;
int V_5 ;
T_1 V_54 [ 4 ] ;
static struct V_55 V_56 ;
V_54 [ 1 ] = 0xFF ;
V_54 [ 2 ] = 0xFF ;
V_54 [ 3 ] = 0xFF ;
V_5 = F_11 ( V_14 , & V_54 [ 0 ] ,
V_57 , 3 ) ;
V_5 = F_11 ( V_14 , & V_54 [ 0 ] ,
V_58 , 3 ) ;
V_5 = F_11 ( V_14 , & V_54 [ 0 ] ,
V_15 , 3 ) ;
V_19 = V_49 ;
V_56 = V_59 ;
V_56 . V_60 = L_10 ;
V_56 . V_61 = NULL ;
for ( V_9 = V_49 ; V_9 < V_50 ; V_9 ++ ) {
F_28 ( V_9 , & V_56 ,
V_62 ) ;
F_15 ( V_9 ) ;
}
V_63 = V_9 ;
F_29 ( L_11 , L_12 ,
V_48 , V_49 , V_63 - 1 ) ;
F_30 ( & V_13 ) ;
V_53 = F_31 ( F_1 , ( void * ) V_48 , L_13 ) ;
if ( F_32 ( V_53 ) ) {
F_24 ( L_14 , V_48 ) ;
V_51 = F_33 ( V_53 ) ;
goto V_64;
}
V_51 = F_34 ( V_48 , F_13 , V_65 ,
L_15 , & V_13 ) ;
if ( V_51 < 0 ) {
F_24 ( L_16 , V_48 , V_51 ) ;
goto V_66;
}
return V_51 ;
V_66:
F_35 ( V_48 , & V_13 ) ;
V_64:
for ( V_9 = V_49 ; V_9 < V_50 ; V_9 ++ )
F_28 ( V_9 , NULL , NULL ) ;
return V_51 ;
}
int F_36 ( void )
{
if ( V_19 ) {
F_24 ( L_17 ) ;
return - V_67 ;
}
return 0 ;
}
