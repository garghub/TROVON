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
static void F_9 ( unsigned int V_8 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
unsigned long V_11 , V_12 , V_13 ;
unsigned long V_14 , V_15 , V_16 , V_17 ;
V_2 = F_3 ( NULL , NULL , L_2 ) ;
if ( ! V_2 ) {
F_8 ( L_3 ) ;
return;
}
V_10 = F_10 ( V_2 , 0 ) ;
if ( F_11 ( V_10 ) ) {
V_10 = F_12 ( V_2 -> V_18 , L_4 ) ;
}
F_5 ( V_2 ) ;
if ( F_11 ( V_10 ) ) {
F_8 ( L_5 ) ;
return;
}
if ( F_13 ( V_10 ) ) {
F_8 ( L_6 ) ;
return;
}
F_14 ( L_7 , V_8 ) ;
V_8 = ( 1000000000 / V_8 ) * 1000 ;
F_14 ( L_8 , V_8 ) ;
V_11 = V_8 / 20 ;
F_14 ( L_9 , V_11 ) ;
V_12 = V_8 - V_11 ;
V_13 = V_8 + V_11 ;
F_14 ( L_10 , V_12 ) ;
F_14 ( L_11 , V_13 ) ;
for ( V_14 = 0 ; V_14 <= V_11 ; V_14 += V_8 / 64 ) {
V_15 = V_8 - V_14 ;
F_14 ( L_12 , V_15 ) ;
F_15 ( V_10 , V_15 ) ;
V_16 = F_16 ( V_10 ) ;
V_17 = abs ( V_8 - V_16 ) ;
if ( V_17 < V_11 )
break;
if ( ! V_14 )
continue;
V_15 = V_8 + V_14 ;
F_14 ( L_12 , V_15 ) ;
F_15 ( V_10 , V_15 ) ;
V_16 = F_16 ( V_10 ) ;
V_17 = abs ( V_8 - V_16 ) ;
if ( V_17 < V_11 )
break;
}
if ( V_14 <= V_11 ) {
F_14 ( L_13 , V_15 ) ;
F_14 ( L_14 ,
V_8 , V_16 , V_17 , V_11 ) ;
return;
}
F_17 ( L_15 ) ;
F_17 ( L_16 ) ;
F_15 ( V_10 , V_8 ) ;
V_16 = F_16 ( V_10 ) ;
V_17 = abs ( V_8 - V_16 ) ;
F_14 ( L_14 ,
V_8 , V_16 , V_17 , V_11 ) ;
}
static enum V_19
F_18 ( enum V_19 V_20 )
{
return V_21 ;
}
static inline void F_19 ( struct V_22 * V_22 )
{
F_20 ( F_21 ( V_22 ) ) ;
F_20 ( F_22 ( & V_22 -> V_23 ) > 1 ) ;
F_23 ( V_22 ) ;
}
static void F_24 ( void )
{
unsigned long V_24 = V_25 . V_26 & V_27 ;
unsigned long V_28 = V_25 . V_29 ;
unsigned long V_30 , V_31 ;
if ( V_25 . V_32 ) {
V_30 = F_25 ( V_24 ) ;
V_31 = F_26 ( V_24 + V_28 ) ;
for (; V_30 < V_31 ; V_30 ++ )
F_19 ( F_27 ( V_30 ) ) ;
V_25 . V_32 = false ;
}
V_33 . V_34 = NULL ;
}
static void T_1 F_28 ( void )
{
struct V_1 * V_2 ;
struct V_35 T_2 * V_36 ;
T_3 V_37 ;
void T_2 * V_38 ;
unsigned long V_39 , V_40 , V_41 , V_42 ;
unsigned long V_43 ;
V_2 = F_3 ( NULL , NULL , L_2 ) ;
if ( ! V_2 ) {
F_8 ( L_17 ) ;
return;
}
V_36 = F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
if ( ! V_36 ) {
F_8 ( L_18 ) ;
return;
}
V_39 = F_29 ( & V_36 -> V_44 ) ;
if ( V_39 == V_45 ) {
F_30 ( L_19 , V_46 ) ;
goto V_47;
}
V_37 = F_29 ( & V_36 -> V_37 [ 0 ] ) ;
V_38 = F_31 ( V_37 , sizeof( struct V_48 ) ) ;
if ( ! V_38 ) {
F_8 ( L_20 ) ;
goto V_47;
}
memcpy ( & V_25 . V_49 , V_38 , sizeof( struct V_48 ) ) ;
V_43 = ( unsigned long ) & V_25 . V_49 ;
F_32 ( V_43 , V_43 + sizeof( struct V_48 ) - 1 ) ;
V_41 = F_29 ( & V_36 -> V_50 ) ;
V_40 = F_33 ( V_38 ) ;
V_42 = ( ( V_40 >> 16 ) & 0x3 ) + 1 ;
V_25 . V_26 = F_33 ( V_38 + 4 ) ;
V_25 . V_29 = ( ( V_41 & 0xfff0000 ) >> 16 ) * ( V_41 & 0xfff ) * V_42 ;
V_25 . V_32 = true ;
F_34 ( V_38 ) ;
V_37 = F_29 ( & V_36 -> gamma ) ;
V_38 = F_31 ( V_37 , sizeof( V_25 . gamma ) ) ;
if ( ! V_38 ) {
F_8 ( L_20 ) ;
V_25 . V_32 = false ;
goto V_47;
}
memcpy ( & V_25 . gamma , V_38 , sizeof( V_25 . gamma ) ) ;
V_43 = ( unsigned long ) & V_25 . gamma ;
F_32 ( V_43 , V_43 + sizeof( V_25 . gamma ) - 1 ) ;
F_34 ( V_38 ) ;
F_7 ( & V_36 -> gamma , F_35 ( & V_25 . gamma ) ) ;
F_7 ( & V_36 -> V_37 [ 1 ] , 0 ) ;
F_7 ( & V_36 -> V_37 [ 2 ] , 0 ) ;
F_7 ( & V_36 -> V_37 [ 0 ] , F_35 ( & V_25 . V_49 ) ) ;
V_47:
F_34 ( V_36 ) ;
}
static void T_1 F_36 ( void )
{
int V_51 ;
if ( V_25 . V_32 ) {
V_51 = F_37 ( V_25 . V_26 ,
V_25 . V_29 ,
V_52 ) ;
if ( V_51 ) {
F_8 ( L_21 , V_46 ) ;
V_25 . V_32 = false ;
}
}
V_33 . V_53 = F_9 ;
V_33 . V_54 = F_18 ;
V_33 . V_34 = F_24 ;
}
void T_1 F_38 ( void )
{
struct V_1 * V_2 ;
V_2 = F_3 ( NULL , NULL , L_22 ) ;
if ( ! V_2 )
return;
F_39 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
F_40 () ;
}
static void T_1 F_41 ( void )
{
if ( F_42 ( NULL , V_55 , NULL ) )
F_43 (KERN_ERR __FILE__ L_23
L_24 ) ;
}
const char * F_44 ( void )
{
if ( F_45 ( L_25 ) )
return L_26 ;
if ( F_45 ( L_27 ) )
return L_28 ;
return NULL ;
}
const char * F_2 ( void )
{
if ( F_45 ( L_25 ) )
return L_29 ;
if ( F_45 ( L_27 ) )
return L_30 ;
return NULL ;
}
static unsigned int T_1 F_46 ( struct V_1 * V_2 ,
char * V_56 )
{
const unsigned int * V_57 ;
V_57 = F_47 ( V_2 , V_56 , NULL ) ;
if ( V_57 )
return * V_57 ;
F_48 ( L_31 ,
V_56 , V_2 -> V_58 , V_59 ) ;
return V_59 ;
}
static void T_1 F_49 ( void )
{
struct V_1 * V_2 ;
void T_2 * V_60 ;
unsigned int V_61 ;
unsigned int V_62 ;
const char * V_63 ;
int V_64 = 0 ;
V_63 = F_44 () ;
if ( ! V_63 ) {
F_8 ( L_32 , V_46 ) ;
return;
}
F_50 (np, NULL, psc_compat) {
V_61 = F_46 ( V_2 , L_33 ) ;
V_62 = F_46 ( V_2 , L_34 ) ;
V_61 /= 4 ;
V_62 /= 4 ;
if ( ! V_61 )
V_61 = 1 ;
if ( ! V_62 )
V_62 = 1 ;
V_60 = F_4 ( V_2 , 0 ) ;
if ( ! V_60 ) {
F_8 ( L_35 ,
V_46 , V_2 -> V_58 ) ;
continue;
}
if ( ( V_64 + V_61 + V_62 ) > 0x1000 ) {
F_8 ( L_36 ,
V_46 , V_2 -> V_58 ) ;
F_34 ( V_60 ) ;
continue;
}
F_7 ( & F_51 ( V_60 ) -> V_65 , ( V_64 << 16 ) | V_61 ) ;
V_64 += V_61 ;
F_7 ( & F_51 ( V_60 ) -> V_66 , ( V_64 << 16 ) | V_62 ) ;
V_64 += V_62 ;
F_7 ( & F_51 ( V_60 ) -> V_67 , 0x80 ) ;
F_7 ( & F_51 ( V_60 ) -> V_67 , 0x01 ) ;
F_7 ( & F_51 ( V_60 ) -> V_68 , 0x80 ) ;
F_7 ( & F_51 ( V_60 ) -> V_68 , 0x01 ) ;
F_34 ( V_60 ) ;
}
}
void T_1 F_52 ( void )
{
F_1 () ;
if ( F_53 ( V_69 ) )
F_28 () ;
}
void T_1 F_54 ( void )
{
F_55 () ;
F_41 () ;
F_49 () ;
}
void T_1 F_56 ( void )
{
if ( F_53 ( V_69 ) )
F_36 () ;
}
int F_57 ( unsigned int V_70 , T_4 V_71 )
{
static struct V_72 T_2 * V_73 ;
struct V_1 * V_2 ;
if ( V_70 > 7 )
return - V_74 ;
if ( ! V_73 ) {
V_2 = F_3 ( NULL , NULL , L_37 ) ;
V_73 = F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
if ( ! V_73 )
return - V_75 ;
}
F_7 ( & V_73 -> V_76 [ V_70 ] , V_71 ) ;
return 0 ;
}
