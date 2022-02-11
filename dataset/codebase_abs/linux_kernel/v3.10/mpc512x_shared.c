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
void F_8 ( unsigned int V_7 )
{
unsigned long V_8 , V_9 , V_10 , V_11 ;
unsigned long V_12 , V_13 , V_14 ;
struct V_15 T_2 * V_16 ;
struct V_1 * V_2 ;
T_3 V_17 ;
long V_18 ;
int V_19 ;
V_2 = F_2 ( NULL , NULL , L_3 ) ;
if ( ! V_2 ) {
F_7 ( L_4 ) ;
return;
}
V_16 = F_3 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
if ( ! V_16 ) {
F_7 ( L_5 ) ;
return;
}
V_2 = F_9 ( NULL , L_6 ) ;
if ( V_2 ) {
const unsigned int * V_20 =
F_10 ( V_2 , L_7 , NULL ) ;
F_4 ( V_2 ) ;
if ( V_20 ) {
V_11 = * V_20 ;
} else {
F_7 ( L_8 ) ;
return;
}
} else {
F_7 ( L_9 ) ;
return;
}
F_11 ( L_10 , V_11 ) ;
V_10 = V_11 * 4 ;
F_11 ( L_11 , V_7 ) ;
V_17 = ( 1000000000 / V_7 ) * 1000 ;
V_7 = V_17 ;
F_11 ( L_12 , V_7 ) ;
V_17 = V_17 / 20 ;
F_11 ( L_13 , V_17 ) ;
V_12 = V_7 - V_17 ;
V_13 = V_7 + V_17 ;
F_11 ( L_14 , V_12 ) ;
F_11 ( L_15 , V_13 ) ;
V_14 = V_10 / V_7 ;
F_11 ( L_16 , V_14 ) ;
V_18 = V_21 ;
V_8 = V_14 ;
F_11 ( L_17 , V_8 ) ;
V_9 = 0 ;
for ( V_19 = - 1 ; V_19 <= 1 ; V_19 ++ ) {
V_17 = V_10 / ( V_14 + V_19 ) ;
F_11 ( L_18 ,
V_19 , V_14 , V_17 ) ;
if ( ( V_17 < V_12 ) || ( V_17 > V_13 ) )
F_11 ( L_19 ,
V_12 , V_13 ) ;
else if ( abs ( V_17 - V_7 ) < V_18 ) {
F_11 ( L_20 , V_19 ) ;
V_18 = abs ( V_17 - V_7 ) ;
V_8 = V_14 + V_19 ;
V_9 = V_17 ;
}
}
F_11 ( L_21 , V_8 ) ;
F_11 ( L_22 , V_18 ) ;
F_11 ( L_23 , V_9 ) ;
V_17 = F_12 ( & V_16 -> V_22 ) ;
F_11 ( L_24 , V_17 ) ;
V_17 &= ~ V_23 ;
V_17 |= ( V_8 & V_23 ) ;
F_6 ( & V_16 -> V_22 , V_17 ) ;
F_11 ( L_25 , V_17 ) ;
F_13 ( V_16 ) ;
}
enum V_24
F_14 ( enum V_24 V_25 )
{
return V_26 ;
}
static inline void F_15 ( struct V_27 * V_27 )
{
F_16 ( F_17 ( V_27 ) ) ;
F_16 ( F_18 ( & V_27 -> V_28 ) > 1 ) ;
F_19 ( V_27 ) ;
}
void F_20 ( void )
{
unsigned long V_29 = V_30 . V_31 & V_32 ;
unsigned long V_33 = V_30 . V_34 ;
unsigned long V_35 , V_36 ;
if ( V_30 . V_37 ) {
V_35 = F_21 ( V_29 ) ;
V_36 = F_22 ( V_29 + V_33 ) ;
for (; V_35 < V_36 ; V_35 ++ )
F_15 ( F_23 ( V_35 ) ) ;
V_30 . V_37 = false ;
}
V_38 . V_39 = NULL ;
}
void T_1 F_24 ( void )
{
struct V_1 * V_2 ;
struct V_40 T_2 * V_41 ;
T_4 V_42 ;
void T_2 * V_43 ;
unsigned long V_44 , V_45 , V_46 , V_47 ;
unsigned long V_48 ;
V_2 = F_2 ( NULL , NULL , L_26 ) ;
if ( ! V_2 ) {
F_7 ( L_27 ) ;
return;
}
V_41 = F_3 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
if ( ! V_41 ) {
F_7 ( L_28 ) ;
return;
}
V_44 = F_12 ( & V_41 -> V_49 ) ;
if ( V_44 == V_50 ) {
F_25 ( L_29 , V_51 ) ;
goto V_52;
}
V_42 = F_12 ( & V_41 -> V_42 [ 0 ] ) ;
V_43 = F_26 ( V_42 , sizeof( struct V_53 ) ) ;
if ( ! V_43 ) {
F_7 ( L_30 ) ;
goto V_52;
}
memcpy ( & V_30 . V_54 , V_43 , sizeof( struct V_53 ) ) ;
V_48 = ( unsigned long ) & V_30 . V_54 ;
F_27 ( V_48 , V_48 + sizeof( struct V_53 ) - 1 ) ;
V_46 = F_12 ( & V_41 -> V_55 ) ;
V_45 = F_28 ( V_43 ) ;
V_47 = ( ( V_45 >> 16 ) & 0x3 ) + 1 ;
V_30 . V_31 = F_28 ( V_43 + 4 ) ;
V_30 . V_34 = ( ( V_46 & 0xfff0000 ) >> 16 ) * ( V_46 & 0xfff ) * V_47 ;
V_30 . V_37 = true ;
F_13 ( V_43 ) ;
V_42 = F_12 ( & V_41 -> gamma ) ;
V_43 = F_26 ( V_42 , sizeof( V_30 . gamma ) ) ;
if ( ! V_43 ) {
F_7 ( L_30 ) ;
V_30 . V_37 = false ;
goto V_52;
}
memcpy ( & V_30 . gamma , V_43 , sizeof( V_30 . gamma ) ) ;
V_48 = ( unsigned long ) & V_30 . gamma ;
F_27 ( V_48 , V_48 + sizeof( V_30 . gamma ) - 1 ) ;
F_13 ( V_43 ) ;
F_6 ( & V_41 -> gamma , F_29 ( & V_30 . gamma ) ) ;
F_6 ( & V_41 -> V_42 [ 1 ] , 0 ) ;
F_6 ( & V_41 -> V_42 [ 2 ] , 0 ) ;
F_6 ( & V_41 -> V_42 [ 0 ] , F_29 ( & V_30 . V_54 ) ) ;
V_52:
F_13 ( V_41 ) ;
}
void T_1 F_30 ( void )
{
int V_56 ;
if ( V_30 . V_37 ) {
V_56 = F_31 ( V_30 . V_31 ,
V_30 . V_34 ,
V_57 ) ;
if ( V_56 ) {
F_7 ( L_31 , V_51 ) ;
V_30 . V_37 = false ;
}
}
V_38 . V_58 = F_8 ;
V_38 . V_59 = F_14 ;
V_38 . V_39 = F_20 ;
}
void T_1 F_32 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( NULL , NULL , L_32 ) ;
if ( ! V_2 )
return;
F_33 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
F_34 () ;
}
void T_1 F_35 ( void )
{
if ( F_36 ( NULL , V_60 , NULL ) )
F_37 (KERN_ERR __FILE__ L_33
L_34 ) ;
}
const char * F_38 ( void )
{
if ( F_39 ( L_35 ) )
return L_36 ;
if ( F_39 ( L_37 ) )
return L_38 ;
return NULL ;
}
static unsigned int T_1 F_40 ( struct V_1 * V_2 ,
char * V_61 )
{
const unsigned int * V_62 ;
V_62 = F_10 ( V_2 , V_61 , NULL ) ;
if ( V_62 )
return * V_62 ;
F_41 ( L_39 ,
V_61 , V_2 -> V_63 , V_64 ) ;
return V_64 ;
}
void T_1 F_42 ( void )
{
struct V_1 * V_2 ;
void T_2 * V_65 ;
unsigned int V_66 ;
unsigned int V_67 ;
const char * V_68 ;
int V_69 = 0 ;
V_68 = F_38 () ;
if ( ! V_68 ) {
F_7 ( L_40 , V_51 ) ;
return;
}
F_43 (np, NULL, psc_compat) {
V_66 = F_40 ( V_2 , L_41 ) ;
V_67 = F_40 ( V_2 , L_42 ) ;
V_66 /= 4 ;
V_67 /= 4 ;
if ( ! V_66 )
V_66 = 1 ;
if ( ! V_67 )
V_67 = 1 ;
V_65 = F_3 ( V_2 , 0 ) ;
if ( ! V_65 ) {
F_7 ( L_43 ,
V_51 , V_2 -> V_63 ) ;
continue;
}
if ( ( V_69 + V_66 + V_67 ) > 0x1000 ) {
F_7 ( L_44 ,
V_51 , V_2 -> V_63 ) ;
F_13 ( V_65 ) ;
continue;
}
F_6 ( & F_44 ( V_65 ) -> V_70 , ( V_69 << 16 ) | V_66 ) ;
V_69 += V_66 ;
F_6 ( & F_44 ( V_65 ) -> V_71 , ( V_69 << 16 ) | V_67 ) ;
V_69 += V_67 ;
F_6 ( & F_44 ( V_65 ) -> V_72 , 0x80 ) ;
F_6 ( & F_44 ( V_65 ) -> V_72 , 0x01 ) ;
F_6 ( & F_44 ( V_65 ) -> V_73 , 0x80 ) ;
F_6 ( & F_44 ( V_65 ) -> V_73 , 0x01 ) ;
F_13 ( V_65 ) ;
}
}
void T_1 F_45 ( void )
{
F_46 () ;
F_35 () ;
F_1 () ;
F_42 () ;
}
int F_47 ( unsigned int V_74 , T_3 V_75 )
{
static struct V_76 T_2 * V_77 ;
struct V_1 * V_2 ;
if ( V_74 > 7 )
return - V_78 ;
if ( ! V_77 ) {
V_2 = F_2 ( NULL , NULL , L_45 ) ;
V_77 = F_3 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
if ( ! V_77 )
return - V_79 ;
}
F_6 ( & V_77 -> V_80 [ V_74 ] , V_75 ) ;
return 0 ;
}
