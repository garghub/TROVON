static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
const char * V_3 ;
V_3 = F_2 () ;
V_2 = F_3 ( NULL , NULL , V_3 ) ;
if ( ! V_2 )
return;
V_4 = F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
}
void F_6 ( char * V_5 )
{
if ( V_4 ) {
F_7 ( & V_4 -> V_6 , 0x52535445 ) ;
F_7 ( & V_4 -> V_7 , 0x2 ) ;
} else {
F_8 ( L_1 ) ;
}
for (; ; )
;
}
void F_9 ( unsigned int V_8 )
{
unsigned long V_9 , V_10 , V_11 , V_12 ;
unsigned long V_13 , V_14 , V_15 ;
struct V_16 T_2 * V_17 ;
struct V_1 * V_2 ;
T_3 V_18 ;
long V_19 ;
int V_20 ;
V_2 = F_3 ( NULL , NULL , L_2 ) ;
if ( ! V_2 ) {
F_8 ( L_3 ) ;
return;
}
V_17 = F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
if ( ! V_17 ) {
F_8 ( L_4 ) ;
return;
}
V_2 = F_10 ( NULL , L_5 ) ;
if ( V_2 ) {
const unsigned int * V_21 =
F_11 ( V_2 , L_6 , NULL ) ;
F_5 ( V_2 ) ;
if ( V_21 ) {
V_12 = * V_21 ;
} else {
F_8 ( L_7 ) ;
return;
}
} else {
F_8 ( L_8 ) ;
return;
}
F_12 ( L_9 , V_12 ) ;
V_11 = V_12 * 4 ;
F_12 ( L_10 , V_8 ) ;
V_18 = ( 1000000000 / V_8 ) * 1000 ;
V_8 = V_18 ;
F_12 ( L_11 , V_8 ) ;
V_18 = V_18 / 20 ;
F_12 ( L_12 , V_18 ) ;
V_13 = V_8 - V_18 ;
V_14 = V_8 + V_18 ;
F_12 ( L_13 , V_13 ) ;
F_12 ( L_14 , V_14 ) ;
V_15 = V_11 / V_8 ;
F_12 ( L_15 , V_15 ) ;
V_19 = V_22 ;
V_9 = V_15 ;
F_12 ( L_16 , V_9 ) ;
V_10 = 0 ;
for ( V_20 = - 1 ; V_20 <= 1 ; V_20 ++ ) {
V_18 = V_11 / ( V_15 + V_20 ) ;
F_12 ( L_17 ,
V_20 , V_15 , V_18 ) ;
if ( ( V_18 < V_13 ) || ( V_18 > V_14 ) )
F_12 ( L_18 ,
V_13 , V_14 ) ;
else if ( abs ( V_18 - V_8 ) < V_19 ) {
F_12 ( L_19 , V_20 ) ;
V_19 = abs ( V_18 - V_8 ) ;
V_9 = V_15 + V_20 ;
V_10 = V_18 ;
}
}
F_12 ( L_20 , V_9 ) ;
F_12 ( L_21 , V_19 ) ;
F_12 ( L_22 , V_10 ) ;
V_18 = F_13 ( & V_17 -> V_23 ) ;
F_12 ( L_23 , V_18 ) ;
V_18 &= ~ V_24 ;
V_18 |= ( V_9 & V_24 ) ;
F_7 ( & V_17 -> V_23 , V_18 ) ;
F_12 ( L_24 , V_18 ) ;
F_14 ( V_17 ) ;
}
enum V_25
F_15 ( enum V_25 V_26 )
{
return V_27 ;
}
static inline void F_16 ( struct V_28 * V_28 )
{
F_17 ( F_18 ( V_28 ) ) ;
F_17 ( F_19 ( & V_28 -> V_29 ) > 1 ) ;
F_20 ( V_28 ) ;
}
void F_21 ( void )
{
unsigned long V_30 = V_31 . V_32 & V_33 ;
unsigned long V_34 = V_31 . V_35 ;
unsigned long V_36 , V_37 ;
if ( V_31 . V_38 ) {
V_36 = F_22 ( V_30 ) ;
V_37 = F_23 ( V_30 + V_34 ) ;
for (; V_36 < V_37 ; V_36 ++ )
F_16 ( F_24 ( V_36 ) ) ;
V_31 . V_38 = false ;
}
V_39 . V_40 = NULL ;
}
void T_1 F_25 ( void )
{
struct V_1 * V_2 ;
struct V_41 T_2 * V_42 ;
T_4 V_43 ;
void T_2 * V_44 ;
unsigned long V_45 , V_46 , V_47 , V_48 ;
unsigned long V_49 ;
V_2 = F_3 ( NULL , NULL , L_25 ) ;
if ( ! V_2 ) {
F_8 ( L_26 ) ;
return;
}
V_42 = F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
if ( ! V_42 ) {
F_8 ( L_27 ) ;
return;
}
V_45 = F_13 ( & V_42 -> V_50 ) ;
if ( V_45 == V_51 ) {
F_26 ( L_28 , V_52 ) ;
goto V_53;
}
V_43 = F_13 ( & V_42 -> V_43 [ 0 ] ) ;
V_44 = F_27 ( V_43 , sizeof( struct V_54 ) ) ;
if ( ! V_44 ) {
F_8 ( L_29 ) ;
goto V_53;
}
memcpy ( & V_31 . V_55 , V_44 , sizeof( struct V_54 ) ) ;
V_49 = ( unsigned long ) & V_31 . V_55 ;
F_28 ( V_49 , V_49 + sizeof( struct V_54 ) - 1 ) ;
V_47 = F_13 ( & V_42 -> V_56 ) ;
V_46 = F_29 ( V_44 ) ;
V_48 = ( ( V_46 >> 16 ) & 0x3 ) + 1 ;
V_31 . V_32 = F_29 ( V_44 + 4 ) ;
V_31 . V_35 = ( ( V_47 & 0xfff0000 ) >> 16 ) * ( V_47 & 0xfff ) * V_48 ;
V_31 . V_38 = true ;
F_14 ( V_44 ) ;
V_43 = F_13 ( & V_42 -> gamma ) ;
V_44 = F_27 ( V_43 , sizeof( V_31 . gamma ) ) ;
if ( ! V_44 ) {
F_8 ( L_29 ) ;
V_31 . V_38 = false ;
goto V_53;
}
memcpy ( & V_31 . gamma , V_44 , sizeof( V_31 . gamma ) ) ;
V_49 = ( unsigned long ) & V_31 . gamma ;
F_28 ( V_49 , V_49 + sizeof( V_31 . gamma ) - 1 ) ;
F_14 ( V_44 ) ;
F_7 ( & V_42 -> gamma , F_30 ( & V_31 . gamma ) ) ;
F_7 ( & V_42 -> V_43 [ 1 ] , 0 ) ;
F_7 ( & V_42 -> V_43 [ 2 ] , 0 ) ;
F_7 ( & V_42 -> V_43 [ 0 ] , F_30 ( & V_31 . V_55 ) ) ;
V_53:
F_14 ( V_42 ) ;
}
void T_1 F_31 ( void )
{
int V_57 ;
if ( V_31 . V_38 ) {
V_57 = F_32 ( V_31 . V_32 ,
V_31 . V_35 ,
V_58 ) ;
if ( V_57 ) {
F_8 ( L_30 , V_52 ) ;
V_31 . V_38 = false ;
}
}
V_39 . V_59 = F_9 ;
V_39 . V_60 = F_15 ;
V_39 . V_40 = F_21 ;
}
void T_1 F_33 ( void )
{
struct V_1 * V_2 ;
V_2 = F_3 ( NULL , NULL , L_31 ) ;
if ( ! V_2 )
return;
F_34 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
F_35 () ;
}
void T_1 F_36 ( void )
{
if ( F_37 ( NULL , V_61 , NULL ) )
F_38 (KERN_ERR __FILE__ L_32
L_33 ) ;
}
const char * F_39 ( void )
{
if ( F_40 ( L_34 ) )
return L_35 ;
if ( F_40 ( L_36 ) )
return L_37 ;
return NULL ;
}
const char * F_2 ( void )
{
if ( F_40 ( L_34 ) )
return L_38 ;
if ( F_40 ( L_36 ) )
return L_39 ;
return NULL ;
}
static unsigned int T_1 F_41 ( struct V_1 * V_2 ,
char * V_62 )
{
const unsigned int * V_63 ;
V_63 = F_11 ( V_2 , V_62 , NULL ) ;
if ( V_63 )
return * V_63 ;
F_42 ( L_40 ,
V_62 , V_2 -> V_64 , V_65 ) ;
return V_65 ;
}
void T_1 F_43 ( void )
{
struct V_1 * V_2 ;
void T_2 * V_66 ;
unsigned int V_67 ;
unsigned int V_68 ;
const char * V_69 ;
int V_70 = 0 ;
V_69 = F_39 () ;
if ( ! V_69 ) {
F_8 ( L_41 , V_52 ) ;
return;
}
F_44 (np, NULL, psc_compat) {
V_67 = F_41 ( V_2 , L_42 ) ;
V_68 = F_41 ( V_2 , L_43 ) ;
V_67 /= 4 ;
V_68 /= 4 ;
if ( ! V_67 )
V_67 = 1 ;
if ( ! V_68 )
V_68 = 1 ;
V_66 = F_4 ( V_2 , 0 ) ;
if ( ! V_66 ) {
F_8 ( L_44 ,
V_52 , V_2 -> V_64 ) ;
continue;
}
if ( ( V_70 + V_67 + V_68 ) > 0x1000 ) {
F_8 ( L_45 ,
V_52 , V_2 -> V_64 ) ;
F_14 ( V_66 ) ;
continue;
}
F_7 ( & F_45 ( V_66 ) -> V_71 , ( V_70 << 16 ) | V_67 ) ;
V_70 += V_67 ;
F_7 ( & F_45 ( V_66 ) -> V_72 , ( V_70 << 16 ) | V_68 ) ;
V_70 += V_68 ;
F_7 ( & F_45 ( V_66 ) -> V_73 , 0x80 ) ;
F_7 ( & F_45 ( V_66 ) -> V_73 , 0x01 ) ;
F_7 ( & F_45 ( V_66 ) -> V_74 , 0x80 ) ;
F_7 ( & F_45 ( V_66 ) -> V_74 , 0x01 ) ;
F_14 ( V_66 ) ;
}
}
void T_1 F_46 ( void )
{
F_1 () ;
if ( F_47 ( V_75 ) )
F_25 () ;
}
void T_1 F_48 ( void )
{
F_49 () ;
F_36 () ;
F_43 () ;
}
void T_1 F_50 ( void )
{
if ( F_47 ( V_75 ) )
F_31 () ;
}
int F_51 ( unsigned int V_76 , T_3 V_77 )
{
static struct V_78 T_2 * V_79 ;
struct V_1 * V_2 ;
if ( V_76 > 7 )
return - V_80 ;
if ( ! V_79 ) {
V_2 = F_3 ( NULL , NULL , L_46 ) ;
V_79 = F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
if ( ! V_79 )
return - V_81 ;
}
F_7 ( & V_79 -> V_82 [ V_76 ] , V_77 ) ;
return 0 ;
}
