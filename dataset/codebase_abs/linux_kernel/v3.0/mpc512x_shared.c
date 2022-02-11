static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 )
return;
V_3 = F_3 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
}
void F_5 ( char * V_4 )
{
if ( V_3 ) {
F_6 ( & V_3 -> V_5 , 0x52535445 ) ;
F_6 ( & V_3 -> V_6 , 0x2 ) ;
} else {
F_7 ( L_2 ) ;
}
for (; ; )
;
}
unsigned int F_8 ( unsigned int V_7 ,
int V_8 )
{
switch ( V_7 ) {
case 32 :
return 0x88883316 ;
case 24 :
return 0x88082219 ;
case 16 :
return 0x65053118 ;
}
return 0x00000400 ;
}
void F_9 ( int V_8 , char * V_9 )
{
}
void F_10 ( int V_8 )
{
}
void F_11 ( unsigned int V_10 )
{
unsigned long V_11 , V_12 , V_13 , V_14 ;
unsigned long V_15 , V_16 , V_17 ;
struct V_18 T_2 * V_19 ;
struct V_1 * V_2 ;
T_3 V_20 ;
long V_21 ;
int V_22 ;
V_2 = F_2 ( NULL , NULL , L_3 ) ;
if ( ! V_2 ) {
F_7 ( L_4 ) ;
return;
}
V_19 = F_3 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
if ( ! V_19 ) {
F_7 ( L_5 ) ;
return;
}
V_2 = F_12 ( NULL , L_6 ) ;
if ( V_2 ) {
const unsigned int * V_23 =
F_13 ( V_2 , L_7 , NULL ) ;
F_4 ( V_2 ) ;
if ( V_23 ) {
V_14 = * V_23 ;
} else {
F_7 ( L_8 ) ;
return;
}
} else {
F_7 ( L_9 ) ;
return;
}
F_14 ( L_10 , V_14 ) ;
V_13 = V_14 * 4 ;
F_14 ( L_11 , V_10 ) ;
V_20 = ( 1000000000 / V_10 ) * 1000 ;
V_10 = V_20 ;
F_14 ( L_12 , V_10 ) ;
V_20 = V_20 / 20 ;
F_14 ( L_13 , V_20 ) ;
V_15 = V_10 - V_20 ;
V_16 = V_10 + V_20 ;
F_14 ( L_14 , V_15 ) ;
F_14 ( L_15 , V_16 ) ;
V_17 = V_13 / V_10 ;
F_14 ( L_16 , V_17 ) ;
V_21 = V_24 ;
V_11 = V_17 ;
F_14 ( L_17 , V_11 ) ;
V_12 = 0 ;
for ( V_22 = - 1 ; V_22 <= 1 ; V_22 ++ ) {
V_20 = V_13 / ( V_17 + V_22 ) ;
F_14 ( L_18 ,
V_22 , V_17 , V_20 ) ;
if ( ( V_20 < V_15 ) || ( V_20 > V_16 ) )
F_14 ( L_19 ,
V_15 , V_16 ) ;
else if ( abs ( V_20 - V_10 ) < V_21 ) {
F_14 ( L_20 , V_22 ) ;
V_21 = abs ( V_20 - V_10 ) ;
V_11 = V_17 + V_22 ;
V_12 = V_20 ;
}
}
F_14 ( L_21 , V_11 ) ;
F_14 ( L_22 , V_21 ) ;
F_14 ( L_23 , V_12 ) ;
V_20 = F_15 ( & V_19 -> V_25 ) ;
F_14 ( L_24 , V_20 ) ;
V_20 &= ~ V_26 ;
V_20 |= ( V_11 & V_26 ) ;
F_6 ( & V_19 -> V_25 , V_20 ) ;
F_14 ( L_25 , V_20 ) ;
F_16 ( V_19 ) ;
}
T_4 F_17 ( int V_8 , char * V_27 )
{
return sprintf ( V_27 , L_26 ) ;
}
int F_18 ( int V_28 )
{
return 0 ;
}
static inline void F_19 ( struct V_29 * V_29 )
{
F_20 ( V_29 ) ;
F_21 ( F_22 ( V_29 ) ) ;
F_21 ( F_23 ( & V_29 -> V_30 ) > 1 ) ;
F_24 ( & V_29 -> V_30 , 1 ) ;
F_25 ( V_29 ) ;
V_31 ++ ;
}
void F_26 ( void )
{
unsigned long V_32 = V_33 . V_34 & V_35 ;
unsigned long V_36 = V_33 . V_37 ;
unsigned long V_38 , V_39 ;
if ( V_33 . V_40 ) {
V_38 = F_27 ( V_32 ) ;
V_39 = F_28 ( V_32 + V_36 ) ;
for (; V_38 < V_39 ; V_38 ++ )
F_19 ( F_29 ( V_38 ) ) ;
V_33 . V_40 = false ;
}
V_41 . V_42 = NULL ;
}
void T_1 F_30 ( void )
{
struct V_1 * V_2 ;
struct V_43 T_2 * V_44 ;
T_5 V_45 ;
void T_2 * V_46 ;
unsigned long V_47 , V_48 , V_49 , V_50 ;
unsigned long V_51 ;
V_2 = F_2 ( NULL , NULL , L_27 ) ;
if ( ! V_2 ) {
F_7 ( L_28 ) ;
return;
}
V_44 = F_3 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
if ( ! V_44 ) {
F_7 ( L_29 ) ;
return;
}
V_47 = F_15 ( & V_44 -> V_52 ) ;
if ( V_47 != V_53 ) {
F_31 ( L_30 , V_54 ) ;
goto V_55;
}
V_45 = F_15 ( & V_44 -> V_45 [ 0 ] ) ;
V_46 = F_32 ( V_45 , sizeof( struct V_56 ) ) ;
if ( ! V_46 ) {
F_7 ( L_31 ) ;
goto V_55;
}
memcpy ( & V_33 . V_57 , V_46 , sizeof( struct V_56 ) ) ;
V_51 = ( unsigned long ) & V_33 . V_57 ;
F_33 ( V_51 , V_51 + sizeof( struct V_56 ) - 1 ) ;
V_49 = F_15 ( & V_44 -> V_58 ) ;
V_48 = F_34 ( V_46 ) ;
V_50 = ( ( V_48 >> 16 ) & 0x3 ) + 1 ;
V_33 . V_34 = F_34 ( V_46 + 4 ) ;
V_33 . V_37 = ( ( V_49 & 0xfff0000 ) >> 16 ) * ( V_49 & 0xfff ) * V_50 ;
V_33 . V_40 = true ;
F_16 ( V_46 ) ;
V_45 = F_15 ( & V_44 -> gamma ) ;
V_46 = F_32 ( V_45 , sizeof( V_33 . gamma ) ) ;
if ( ! V_46 ) {
F_7 ( L_31 ) ;
V_33 . V_40 = false ;
goto V_55;
}
memcpy ( & V_33 . gamma , V_46 , sizeof( V_33 . gamma ) ) ;
V_51 = ( unsigned long ) & V_33 . gamma ;
F_33 ( V_51 , V_51 + sizeof( V_33 . gamma ) - 1 ) ;
F_16 ( V_46 ) ;
F_6 ( & V_44 -> gamma , F_35 ( & V_33 . gamma ) ) ;
F_6 ( & V_44 -> V_45 [ 1 ] , 0 ) ;
F_6 ( & V_44 -> V_45 [ 2 ] , 0 ) ;
F_6 ( & V_44 -> V_45 [ 0 ] , F_35 ( & V_33 . V_57 ) ) ;
V_55:
F_16 ( V_44 ) ;
}
void T_1 F_36 ( void )
{
int V_59 ;
if ( V_33 . V_40 ) {
V_59 = F_37 ( V_33 . V_34 ,
V_33 . V_37 ,
V_60 ) ;
if ( V_59 ) {
F_7 ( L_32 , V_54 ) ;
V_33 . V_40 = false ;
}
}
#if F_38 ( V_61 ) || \
F_38 ( V_62 )
V_41 . V_63 = F_8 ;
V_41 . V_64 = F_9 ;
V_41 . V_65 = F_10 ;
V_41 . V_66 = F_11 ;
V_41 . V_67 = F_17 ;
V_41 . V_68 = F_18 ;
V_41 . V_42 = F_26 ;
#endif
}
void T_1 F_39 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( NULL , NULL , L_33 ) ;
if ( ! V_2 )
return;
F_40 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
F_41 () ;
}
void T_1 F_42 ( void )
{
struct V_1 * V_2 ;
if ( F_43 ( NULL , V_69 , NULL ) )
F_44 (KERN_ERR __FILE__ L_34
L_35 ) ;
V_2 = F_2 ( NULL , NULL , L_36 ) ;
if ( V_2 ) {
F_45 ( V_2 , NULL , NULL ) ;
F_4 ( V_2 ) ;
}
}
static unsigned int T_1 F_46 ( struct V_1 * V_2 ,
char * V_70 )
{
const unsigned int * V_71 ;
V_71 = F_13 ( V_2 , V_70 , NULL ) ;
if ( V_71 )
return * V_71 ;
F_47 ( L_37 ,
V_70 , V_2 -> V_72 , V_73 ) ;
return V_73 ;
}
void T_1 F_48 ( void )
{
struct V_1 * V_2 ;
void T_2 * V_74 ;
unsigned int V_75 ;
unsigned int V_76 ;
int V_77 = 0 ;
F_49 (np, NULL, L_38 ) {
V_75 = F_46 ( V_2 , L_39 ) ;
V_76 = F_46 ( V_2 , L_40 ) ;
V_75 /= 4 ;
V_76 /= 4 ;
if ( ! V_75 )
V_75 = 1 ;
if ( ! V_76 )
V_76 = 1 ;
V_74 = F_3 ( V_2 , 0 ) ;
if ( ! V_74 ) {
F_7 ( L_41 ,
V_54 , V_2 -> V_72 ) ;
continue;
}
if ( ( V_77 + V_75 + V_76 ) > 0x1000 ) {
F_7 ( L_42 ,
V_54 , V_2 -> V_72 ) ;
F_16 ( V_74 ) ;
continue;
}
F_6 ( & F_50 ( V_74 ) -> V_78 , ( V_77 << 16 ) | V_75 ) ;
V_77 += V_75 ;
F_6 ( & F_50 ( V_74 ) -> V_79 , ( V_77 << 16 ) | V_76 ) ;
V_77 += V_76 ;
F_6 ( & F_50 ( V_74 ) -> V_80 , 0x80 ) ;
F_6 ( & F_50 ( V_74 ) -> V_80 , 0x01 ) ;
F_6 ( & F_50 ( V_74 ) -> V_81 , 0x80 ) ;
F_6 ( & F_50 ( V_74 ) -> V_81 , 0x01 ) ;
F_16 ( V_74 ) ;
}
}
void T_1 F_51 ( void )
{
F_42 () ;
F_52 () ;
F_1 () ;
F_48 () ;
}
