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
T_2 F_8 ( enum V_7 V_8 ,
unsigned int V_9 )
{
switch ( V_9 ) {
case 32 :
return 0x88883316 ;
case 24 :
return 0x88082219 ;
case 16 :
return 0x65053118 ;
}
return 0x00000400 ;
}
void F_9 ( enum V_7 V_8 ,
char * V_10 )
{
}
void F_10 ( enum V_7 V_8 )
{
}
void F_11 ( unsigned int V_11 )
{
unsigned long V_12 , V_13 , V_14 , V_15 ;
unsigned long V_16 , V_17 , V_18 ;
struct V_19 T_3 * V_20 ;
struct V_1 * V_2 ;
T_2 V_21 ;
long V_22 ;
int V_23 ;
V_2 = F_2 ( NULL , NULL , L_3 ) ;
if ( ! V_2 ) {
F_7 ( L_4 ) ;
return;
}
V_20 = F_3 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
if ( ! V_20 ) {
F_7 ( L_5 ) ;
return;
}
V_2 = F_12 ( NULL , L_6 ) ;
if ( V_2 ) {
const unsigned int * V_24 =
F_13 ( V_2 , L_7 , NULL ) ;
F_4 ( V_2 ) ;
if ( V_24 ) {
V_15 = * V_24 ;
} else {
F_7 ( L_8 ) ;
return;
}
} else {
F_7 ( L_9 ) ;
return;
}
F_14 ( L_10 , V_15 ) ;
V_14 = V_15 * 4 ;
F_14 ( L_11 , V_11 ) ;
V_21 = ( 1000000000 / V_11 ) * 1000 ;
V_11 = V_21 ;
F_14 ( L_12 , V_11 ) ;
V_21 = V_21 / 20 ;
F_14 ( L_13 , V_21 ) ;
V_16 = V_11 - V_21 ;
V_17 = V_11 + V_21 ;
F_14 ( L_14 , V_16 ) ;
F_14 ( L_15 , V_17 ) ;
V_18 = V_14 / V_11 ;
F_14 ( L_16 , V_18 ) ;
V_22 = V_25 ;
V_12 = V_18 ;
F_14 ( L_17 , V_12 ) ;
V_13 = 0 ;
for ( V_23 = - 1 ; V_23 <= 1 ; V_23 ++ ) {
V_21 = V_14 / ( V_18 + V_23 ) ;
F_14 ( L_18 ,
V_23 , V_18 , V_21 ) ;
if ( ( V_21 < V_16 ) || ( V_21 > V_17 ) )
F_14 ( L_19 ,
V_16 , V_17 ) ;
else if ( abs ( V_21 - V_11 ) < V_22 ) {
F_14 ( L_20 , V_23 ) ;
V_22 = abs ( V_21 - V_11 ) ;
V_12 = V_18 + V_23 ;
V_13 = V_21 ;
}
}
F_14 ( L_21 , V_12 ) ;
F_14 ( L_22 , V_22 ) ;
F_14 ( L_23 , V_13 ) ;
V_21 = F_15 ( & V_20 -> V_26 ) ;
F_14 ( L_24 , V_21 ) ;
V_21 &= ~ V_27 ;
V_21 |= ( V_12 & V_27 ) ;
F_6 ( & V_20 -> V_26 , V_21 ) ;
F_14 ( L_25 , V_21 ) ;
F_16 ( V_20 ) ;
}
enum V_7
F_17 ( enum V_7 V_8 )
{
return V_28 ;
}
static inline void F_18 ( struct V_29 * V_29 )
{
F_19 ( V_29 ) ;
F_20 ( F_21 ( V_29 ) ) ;
F_20 ( F_22 ( & V_29 -> V_30 ) > 1 ) ;
F_23 ( & V_29 -> V_30 , 1 ) ;
F_24 ( V_29 ) ;
V_31 ++ ;
}
void F_25 ( void )
{
unsigned long V_32 = V_33 . V_34 & V_35 ;
unsigned long V_36 = V_33 . V_37 ;
unsigned long V_38 , V_39 ;
if ( V_33 . V_40 ) {
V_38 = F_26 ( V_32 ) ;
V_39 = F_27 ( V_32 + V_36 ) ;
for (; V_38 < V_39 ; V_38 ++ )
F_18 ( F_28 ( V_38 ) ) ;
V_33 . V_40 = false ;
}
V_41 . V_42 = NULL ;
}
void T_1 F_29 ( void )
{
struct V_1 * V_2 ;
struct V_43 T_3 * V_44 ;
T_4 V_45 ;
void T_3 * V_46 ;
unsigned long V_47 , V_48 , V_49 , V_50 ;
unsigned long V_51 ;
V_2 = F_2 ( NULL , NULL , L_26 ) ;
if ( ! V_2 ) {
F_7 ( L_27 ) ;
return;
}
V_44 = F_3 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
if ( ! V_44 ) {
F_7 ( L_28 ) ;
return;
}
V_47 = F_15 ( & V_44 -> V_52 ) ;
if ( V_47 == V_53 ) {
F_30 ( L_29 , V_54 ) ;
goto V_55;
}
V_45 = F_15 ( & V_44 -> V_45 [ 0 ] ) ;
V_46 = F_31 ( V_45 , sizeof( struct V_56 ) ) ;
if ( ! V_46 ) {
F_7 ( L_30 ) ;
goto V_55;
}
memcpy ( & V_33 . V_57 , V_46 , sizeof( struct V_56 ) ) ;
V_51 = ( unsigned long ) & V_33 . V_57 ;
F_32 ( V_51 , V_51 + sizeof( struct V_56 ) - 1 ) ;
V_49 = F_15 ( & V_44 -> V_58 ) ;
V_48 = F_33 ( V_46 ) ;
V_50 = ( ( V_48 >> 16 ) & 0x3 ) + 1 ;
V_33 . V_34 = F_33 ( V_46 + 4 ) ;
V_33 . V_37 = ( ( V_49 & 0xfff0000 ) >> 16 ) * ( V_49 & 0xfff ) * V_50 ;
V_33 . V_40 = true ;
F_16 ( V_46 ) ;
V_45 = F_15 ( & V_44 -> gamma ) ;
V_46 = F_31 ( V_45 , sizeof( V_33 . gamma ) ) ;
if ( ! V_46 ) {
F_7 ( L_30 ) ;
V_33 . V_40 = false ;
goto V_55;
}
memcpy ( & V_33 . gamma , V_46 , sizeof( V_33 . gamma ) ) ;
V_51 = ( unsigned long ) & V_33 . gamma ;
F_32 ( V_51 , V_51 + sizeof( V_33 . gamma ) - 1 ) ;
F_16 ( V_46 ) ;
F_6 ( & V_44 -> gamma , F_34 ( & V_33 . gamma ) ) ;
F_6 ( & V_44 -> V_45 [ 1 ] , 0 ) ;
F_6 ( & V_44 -> V_45 [ 2 ] , 0 ) ;
F_6 ( & V_44 -> V_45 [ 0 ] , F_34 ( & V_33 . V_57 ) ) ;
V_55:
F_16 ( V_44 ) ;
}
void T_1 F_35 ( void )
{
int V_59 ;
if ( V_33 . V_40 ) {
V_59 = F_36 ( V_33 . V_34 ,
V_33 . V_37 ,
V_60 ) ;
if ( V_59 ) {
F_7 ( L_31 , V_54 ) ;
V_33 . V_40 = false ;
}
}
V_41 . V_61 = F_8 ;
V_41 . V_62 = F_9 ;
V_41 . V_63 = F_10 ;
V_41 . V_64 = F_11 ;
V_41 . V_65 = F_17 ;
V_41 . V_42 = F_25 ;
}
void T_1 F_37 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( NULL , NULL , L_32 ) ;
if ( ! V_2 )
return;
F_38 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
F_39 () ;
}
void T_1 F_40 ( void )
{
struct V_1 * V_2 ;
if ( F_41 ( NULL , V_66 , NULL ) )
F_42 (KERN_ERR __FILE__ L_33
L_34 ) ;
V_2 = F_2 ( NULL , NULL , L_35 ) ;
if ( V_2 ) {
F_43 ( V_2 , NULL , NULL ) ;
F_4 ( V_2 ) ;
}
}
static unsigned int T_1 F_44 ( struct V_1 * V_2 ,
char * V_67 )
{
const unsigned int * V_68 ;
V_68 = F_13 ( V_2 , V_67 , NULL ) ;
if ( V_68 )
return * V_68 ;
F_45 ( L_36 ,
V_67 , V_2 -> V_69 , V_70 ) ;
return V_70 ;
}
void T_1 F_46 ( void )
{
struct V_1 * V_2 ;
void T_3 * V_71 ;
unsigned int V_72 ;
unsigned int V_73 ;
int V_74 = 0 ;
F_47 (np, NULL, L_37 ) {
V_72 = F_44 ( V_2 , L_38 ) ;
V_73 = F_44 ( V_2 , L_39 ) ;
V_72 /= 4 ;
V_73 /= 4 ;
if ( ! V_72 )
V_72 = 1 ;
if ( ! V_73 )
V_73 = 1 ;
V_71 = F_3 ( V_2 , 0 ) ;
if ( ! V_71 ) {
F_7 ( L_40 ,
V_54 , V_2 -> V_69 ) ;
continue;
}
if ( ( V_74 + V_72 + V_73 ) > 0x1000 ) {
F_7 ( L_41 ,
V_54 , V_2 -> V_69 ) ;
F_16 ( V_71 ) ;
continue;
}
F_6 ( & F_48 ( V_71 ) -> V_75 , ( V_74 << 16 ) | V_72 ) ;
V_74 += V_72 ;
F_6 ( & F_48 ( V_71 ) -> V_76 , ( V_74 << 16 ) | V_73 ) ;
V_74 += V_73 ;
F_6 ( & F_48 ( V_71 ) -> V_77 , 0x80 ) ;
F_6 ( & F_48 ( V_71 ) -> V_77 , 0x01 ) ;
F_6 ( & F_48 ( V_71 ) -> V_78 , 0x80 ) ;
F_6 ( & F_48 ( V_71 ) -> V_78 , 0x01 ) ;
F_16 ( V_71 ) ;
}
}
void T_1 F_49 ( void )
{
F_40 () ;
F_50 () ;
F_1 () ;
F_46 () ;
}
