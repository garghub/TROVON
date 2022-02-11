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
F_16 ( V_27 ) ;
F_17 ( F_18 ( V_27 ) ) ;
F_17 ( F_19 ( & V_27 -> V_28 ) > 1 ) ;
F_20 ( & V_27 -> V_28 , 1 ) ;
F_21 ( V_27 ) ;
V_29 ++ ;
}
void F_22 ( void )
{
unsigned long V_30 = V_31 . V_32 & V_33 ;
unsigned long V_34 = V_31 . V_35 ;
unsigned long V_36 , V_37 ;
if ( V_31 . V_38 ) {
V_36 = F_23 ( V_30 ) ;
V_37 = F_24 ( V_30 + V_34 ) ;
for (; V_36 < V_37 ; V_36 ++ )
F_15 ( F_25 ( V_36 ) ) ;
V_31 . V_38 = false ;
}
V_39 . V_40 = NULL ;
}
void T_1 F_26 ( void )
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
V_45 = F_12 ( & V_42 -> V_50 ) ;
if ( V_45 == V_51 ) {
F_27 ( L_29 , V_52 ) ;
goto V_53;
}
V_43 = F_12 ( & V_42 -> V_43 [ 0 ] ) ;
V_44 = F_28 ( V_43 , sizeof( struct V_54 ) ) ;
if ( ! V_44 ) {
F_7 ( L_30 ) ;
goto V_53;
}
memcpy ( & V_31 . V_55 , V_44 , sizeof( struct V_54 ) ) ;
V_49 = ( unsigned long ) & V_31 . V_55 ;
F_29 ( V_49 , V_49 + sizeof( struct V_54 ) - 1 ) ;
V_47 = F_12 ( & V_42 -> V_56 ) ;
V_46 = F_30 ( V_44 ) ;
V_48 = ( ( V_46 >> 16 ) & 0x3 ) + 1 ;
V_31 . V_32 = F_30 ( V_44 + 4 ) ;
V_31 . V_35 = ( ( V_47 & 0xfff0000 ) >> 16 ) * ( V_47 & 0xfff ) * V_48 ;
V_31 . V_38 = true ;
F_13 ( V_44 ) ;
V_43 = F_12 ( & V_42 -> gamma ) ;
V_44 = F_28 ( V_43 , sizeof( V_31 . gamma ) ) ;
if ( ! V_44 ) {
F_7 ( L_30 ) ;
V_31 . V_38 = false ;
goto V_53;
}
memcpy ( & V_31 . gamma , V_44 , sizeof( V_31 . gamma ) ) ;
V_49 = ( unsigned long ) & V_31 . gamma ;
F_29 ( V_49 , V_49 + sizeof( V_31 . gamma ) - 1 ) ;
F_13 ( V_44 ) ;
F_6 ( & V_42 -> gamma , F_31 ( & V_31 . gamma ) ) ;
F_6 ( & V_42 -> V_43 [ 1 ] , 0 ) ;
F_6 ( & V_42 -> V_43 [ 2 ] , 0 ) ;
F_6 ( & V_42 -> V_43 [ 0 ] , F_31 ( & V_31 . V_55 ) ) ;
V_53:
F_13 ( V_42 ) ;
}
void T_1 F_32 ( void )
{
int V_57 ;
if ( V_31 . V_38 ) {
V_57 = F_33 ( V_31 . V_32 ,
V_31 . V_35 ,
V_58 ) ;
if ( V_57 ) {
F_7 ( L_31 , V_52 ) ;
V_31 . V_38 = false ;
}
}
V_39 . V_59 = F_8 ;
V_39 . V_60 = F_14 ;
V_39 . V_40 = F_22 ;
}
void T_1 F_34 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( NULL , NULL , L_32 ) ;
if ( ! V_2 )
return;
F_35 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
F_36 () ;
}
void T_1 F_37 ( void )
{
struct V_1 * V_2 ;
if ( F_38 ( NULL , V_61 , NULL ) )
F_39 (KERN_ERR __FILE__ L_33
L_34 ) ;
V_2 = F_2 ( NULL , NULL , L_35 ) ;
if ( V_2 ) {
F_40 ( V_2 , NULL , NULL ) ;
F_4 ( V_2 ) ;
}
}
static unsigned int T_1 F_41 ( struct V_1 * V_2 ,
char * V_62 )
{
const unsigned int * V_63 ;
V_63 = F_10 ( V_2 , V_62 , NULL ) ;
if ( V_63 )
return * V_63 ;
F_42 ( L_36 ,
V_62 , V_2 -> V_64 , V_65 ) ;
return V_65 ;
}
void T_1 F_43 ( void )
{
struct V_1 * V_2 ;
void T_2 * V_66 ;
unsigned int V_67 ;
unsigned int V_68 ;
int V_69 = 0 ;
F_44 (np, NULL, L_37 ) {
V_67 = F_41 ( V_2 , L_38 ) ;
V_68 = F_41 ( V_2 , L_39 ) ;
V_67 /= 4 ;
V_68 /= 4 ;
if ( ! V_67 )
V_67 = 1 ;
if ( ! V_68 )
V_68 = 1 ;
V_66 = F_3 ( V_2 , 0 ) ;
if ( ! V_66 ) {
F_7 ( L_40 ,
V_52 , V_2 -> V_64 ) ;
continue;
}
if ( ( V_69 + V_67 + V_68 ) > 0x1000 ) {
F_7 ( L_41 ,
V_52 , V_2 -> V_64 ) ;
F_13 ( V_66 ) ;
continue;
}
F_6 ( & F_45 ( V_66 ) -> V_70 , ( V_69 << 16 ) | V_67 ) ;
V_69 += V_67 ;
F_6 ( & F_45 ( V_66 ) -> V_71 , ( V_69 << 16 ) | V_68 ) ;
V_69 += V_68 ;
F_6 ( & F_45 ( V_66 ) -> V_72 , 0x80 ) ;
F_6 ( & F_45 ( V_66 ) -> V_72 , 0x01 ) ;
F_6 ( & F_45 ( V_66 ) -> V_73 , 0x80 ) ;
F_6 ( & F_45 ( V_66 ) -> V_73 , 0x01 ) ;
F_13 ( V_66 ) ;
}
}
void T_1 F_46 ( void )
{
F_47 () ;
F_37 () ;
F_1 () ;
F_43 () ;
}
int F_48 ( unsigned int V_74 , T_3 V_75 )
{
static struct V_76 T_2 * V_77 ;
struct V_1 * V_2 ;
if ( V_74 > 7 )
return - V_78 ;
if ( ! V_77 ) {
V_2 = F_2 ( NULL , NULL , L_42 ) ;
V_77 = F_3 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
if ( ! V_77 )
return - V_79 ;
}
F_6 ( & V_77 -> V_80 [ V_74 ] , V_75 ) ;
return 0 ;
}
