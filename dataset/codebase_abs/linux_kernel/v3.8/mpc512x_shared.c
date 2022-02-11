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
void F_8 ( enum V_7 V_8 )
{
}
void F_9 ( unsigned int V_9 )
{
unsigned long V_10 , V_11 , V_12 , V_13 ;
unsigned long V_14 , V_15 , V_16 ;
struct V_17 T_2 * V_18 ;
struct V_1 * V_2 ;
T_3 V_19 ;
long V_20 ;
int V_21 ;
V_2 = F_2 ( NULL , NULL , L_3 ) ;
if ( ! V_2 ) {
F_7 ( L_4 ) ;
return;
}
V_18 = F_3 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
if ( ! V_18 ) {
F_7 ( L_5 ) ;
return;
}
V_2 = F_10 ( NULL , L_6 ) ;
if ( V_2 ) {
const unsigned int * V_22 =
F_11 ( V_2 , L_7 , NULL ) ;
F_4 ( V_2 ) ;
if ( V_22 ) {
V_13 = * V_22 ;
} else {
F_7 ( L_8 ) ;
return;
}
} else {
F_7 ( L_9 ) ;
return;
}
F_12 ( L_10 , V_13 ) ;
V_12 = V_13 * 4 ;
F_12 ( L_11 , V_9 ) ;
V_19 = ( 1000000000 / V_9 ) * 1000 ;
V_9 = V_19 ;
F_12 ( L_12 , V_9 ) ;
V_19 = V_19 / 20 ;
F_12 ( L_13 , V_19 ) ;
V_14 = V_9 - V_19 ;
V_15 = V_9 + V_19 ;
F_12 ( L_14 , V_14 ) ;
F_12 ( L_15 , V_15 ) ;
V_16 = V_12 / V_9 ;
F_12 ( L_16 , V_16 ) ;
V_20 = V_23 ;
V_10 = V_16 ;
F_12 ( L_17 , V_10 ) ;
V_11 = 0 ;
for ( V_21 = - 1 ; V_21 <= 1 ; V_21 ++ ) {
V_19 = V_12 / ( V_16 + V_21 ) ;
F_12 ( L_18 ,
V_21 , V_16 , V_19 ) ;
if ( ( V_19 < V_14 ) || ( V_19 > V_15 ) )
F_12 ( L_19 ,
V_14 , V_15 ) ;
else if ( abs ( V_19 - V_9 ) < V_20 ) {
F_12 ( L_20 , V_21 ) ;
V_20 = abs ( V_19 - V_9 ) ;
V_10 = V_16 + V_21 ;
V_11 = V_19 ;
}
}
F_12 ( L_21 , V_10 ) ;
F_12 ( L_22 , V_20 ) ;
F_12 ( L_23 , V_11 ) ;
V_19 = F_13 ( & V_18 -> V_24 ) ;
F_12 ( L_24 , V_19 ) ;
V_19 &= ~ V_25 ;
V_19 |= ( V_10 & V_25 ) ;
F_6 ( & V_18 -> V_24 , V_19 ) ;
F_12 ( L_25 , V_19 ) ;
F_14 ( V_18 ) ;
}
enum V_7
F_15 ( enum V_7 V_8 )
{
return V_26 ;
}
static inline void F_16 ( struct V_27 * V_27 )
{
F_17 ( V_27 ) ;
F_18 ( F_19 ( V_27 ) ) ;
F_18 ( F_20 ( & V_27 -> V_28 ) > 1 ) ;
F_21 ( & V_27 -> V_28 , 1 ) ;
F_22 ( V_27 ) ;
V_29 ++ ;
}
void F_23 ( void )
{
unsigned long V_30 = V_31 . V_32 & V_33 ;
unsigned long V_34 = V_31 . V_35 ;
unsigned long V_36 , V_37 ;
if ( V_31 . V_38 ) {
V_36 = F_24 ( V_30 ) ;
V_37 = F_25 ( V_30 + V_34 ) ;
for (; V_36 < V_37 ; V_36 ++ )
F_16 ( F_26 ( V_36 ) ) ;
V_31 . V_38 = false ;
}
V_39 . V_40 = NULL ;
}
void T_1 F_27 ( void )
{
struct V_1 * V_2 ;
struct V_41 T_2 * V_42 ;
T_4 V_43 ;
void T_2 * V_44 ;
unsigned long V_45 , V_46 , V_47 , V_48 ;
unsigned long V_49 ;
V_2 = F_2 ( NULL , NULL , L_26 ) ;
if ( ! V_2 ) {
F_7 ( L_27 ) ;
return;
}
V_42 = F_3 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
if ( ! V_42 ) {
F_7 ( L_28 ) ;
return;
}
V_45 = F_13 ( & V_42 -> V_50 ) ;
if ( V_45 == V_51 ) {
F_28 ( L_29 , V_52 ) ;
goto V_53;
}
V_43 = F_13 ( & V_42 -> V_43 [ 0 ] ) ;
V_44 = F_29 ( V_43 , sizeof( struct V_54 ) ) ;
if ( ! V_44 ) {
F_7 ( L_30 ) ;
goto V_53;
}
memcpy ( & V_31 . V_55 , V_44 , sizeof( struct V_54 ) ) ;
V_49 = ( unsigned long ) & V_31 . V_55 ;
F_30 ( V_49 , V_49 + sizeof( struct V_54 ) - 1 ) ;
V_47 = F_13 ( & V_42 -> V_56 ) ;
V_46 = F_31 ( V_44 ) ;
V_48 = ( ( V_46 >> 16 ) & 0x3 ) + 1 ;
V_31 . V_32 = F_31 ( V_44 + 4 ) ;
V_31 . V_35 = ( ( V_47 & 0xfff0000 ) >> 16 ) * ( V_47 & 0xfff ) * V_48 ;
V_31 . V_38 = true ;
F_14 ( V_44 ) ;
V_43 = F_13 ( & V_42 -> gamma ) ;
V_44 = F_29 ( V_43 , sizeof( V_31 . gamma ) ) ;
if ( ! V_44 ) {
F_7 ( L_30 ) ;
V_31 . V_38 = false ;
goto V_53;
}
memcpy ( & V_31 . gamma , V_44 , sizeof( V_31 . gamma ) ) ;
V_49 = ( unsigned long ) & V_31 . gamma ;
F_30 ( V_49 , V_49 + sizeof( V_31 . gamma ) - 1 ) ;
F_14 ( V_44 ) ;
F_6 ( & V_42 -> gamma , F_32 ( & V_31 . gamma ) ) ;
F_6 ( & V_42 -> V_43 [ 1 ] , 0 ) ;
F_6 ( & V_42 -> V_43 [ 2 ] , 0 ) ;
F_6 ( & V_42 -> V_43 [ 0 ] , F_32 ( & V_31 . V_55 ) ) ;
V_53:
F_14 ( V_42 ) ;
}
void T_1 F_33 ( void )
{
int V_57 ;
if ( V_31 . V_38 ) {
V_57 = F_34 ( V_31 . V_32 ,
V_31 . V_35 ,
V_58 ) ;
if ( V_57 ) {
F_7 ( L_31 , V_52 ) ;
V_31 . V_38 = false ;
}
}
V_39 . V_59 = F_8 ;
V_39 . V_60 = F_9 ;
V_39 . V_61 = F_15 ;
V_39 . V_40 = F_23 ;
}
void T_1 F_35 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( NULL , NULL , L_32 ) ;
if ( ! V_2 )
return;
F_36 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
F_37 () ;
}
void T_1 F_38 ( void )
{
struct V_1 * V_2 ;
if ( F_39 ( NULL , V_62 , NULL ) )
F_40 (KERN_ERR __FILE__ L_33
L_34 ) ;
V_2 = F_2 ( NULL , NULL , L_35 ) ;
if ( V_2 ) {
F_41 ( V_2 , NULL , NULL ) ;
F_4 ( V_2 ) ;
}
}
static unsigned int T_1 F_42 ( struct V_1 * V_2 ,
char * V_63 )
{
const unsigned int * V_64 ;
V_64 = F_11 ( V_2 , V_63 , NULL ) ;
if ( V_64 )
return * V_64 ;
F_43 ( L_36 ,
V_63 , V_2 -> V_65 , V_66 ) ;
return V_66 ;
}
void T_1 F_44 ( void )
{
struct V_1 * V_2 ;
void T_2 * V_67 ;
unsigned int V_68 ;
unsigned int V_69 ;
int V_70 = 0 ;
F_45 (np, NULL, L_37 ) {
V_68 = F_42 ( V_2 , L_38 ) ;
V_69 = F_42 ( V_2 , L_39 ) ;
V_68 /= 4 ;
V_69 /= 4 ;
if ( ! V_68 )
V_68 = 1 ;
if ( ! V_69 )
V_69 = 1 ;
V_67 = F_3 ( V_2 , 0 ) ;
if ( ! V_67 ) {
F_7 ( L_40 ,
V_52 , V_2 -> V_65 ) ;
continue;
}
if ( ( V_70 + V_68 + V_69 ) > 0x1000 ) {
F_7 ( L_41 ,
V_52 , V_2 -> V_65 ) ;
F_14 ( V_67 ) ;
continue;
}
F_6 ( & F_46 ( V_67 ) -> V_71 , ( V_70 << 16 ) | V_68 ) ;
V_70 += V_68 ;
F_6 ( & F_46 ( V_67 ) -> V_72 , ( V_70 << 16 ) | V_69 ) ;
V_70 += V_69 ;
F_6 ( & F_46 ( V_67 ) -> V_73 , 0x80 ) ;
F_6 ( & F_46 ( V_67 ) -> V_73 , 0x01 ) ;
F_6 ( & F_46 ( V_67 ) -> V_74 , 0x80 ) ;
F_6 ( & F_46 ( V_67 ) -> V_74 , 0x01 ) ;
F_14 ( V_67 ) ;
}
}
void T_1 F_47 ( void )
{
F_38 () ;
F_48 () ;
F_1 () ;
F_44 () ;
}
