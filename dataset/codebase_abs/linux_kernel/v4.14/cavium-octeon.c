static inline void * F_1 ( T_1 V_1 )
{
return ( void * ) ( V_1 | ( 1ull << 63 ) ) ;
}
static void F_2 ( T_1 V_2 )
{
char * V_3 = F_1 ( V_2 ) ;
asm volatile (
"cache 31, %[line]"
::[line] "m" (*addr_ptr));
}
static void F_3 ( T_1 V_2 )
{
char * V_3 = F_1 ( V_2 ) ;
asm volatile (
"cache 23, %[line]"
::[line] "m" (*addr_ptr));
}
static void F_4 ( T_1 V_4 , T_1 V_5 )
{
T_1 V_6 ;
V_6 = F_5 ( V_4 + V_5 - 1 , V_7 ) ;
V_4 = F_5 ( V_4 , V_7 ) ;
while ( V_4 <= V_6 ) {
F_2 ( V_4 ) ;
V_4 += V_7 ;
}
asm volatile("sync");
}
static void F_6 ( T_1 V_4 , T_1 V_5 )
{
T_1 V_6 ;
V_6 = F_5 ( V_4 + V_5 - 1 , V_7 ) ;
V_4 = F_5 ( V_4 , V_7 ) ;
while ( V_4 <= V_6 ) {
F_3 ( V_4 ) ;
V_4 += V_7 ;
}
}
static void F_7 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_10 ) {
F_8 ( & V_11 ) ;
if ( F_9 ( V_12 ) )
F_10 ( 0 , ( void V_13 * ) V_14 ) ;
} else {
F_8 ( & V_9 -> V_15 ) ;
}
}
static void F_11 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_10 )
F_12 ( & V_11 ) ;
else
F_12 ( & V_9 -> V_15 ) ;
}
static void F_13 ( struct V_8 * V_9 , T_1 V_16 )
{
F_10 ( V_16 , V_9 -> V_17 + F_14 ( V_9 ) ) ;
if ( ! V_9 -> V_10 )
F_10 ( V_16 , V_9 -> V_17 + F_15 ( V_9 ) ) ;
}
static void F_16 ( struct V_8 * V_9 , int V_18 )
{
if ( V_18 == 0 )
if ( ! F_17 ( & V_9 -> V_19 ) )
F_18 ( V_9 -> V_20 , 0 ) ;
if ( V_18 == 1 )
if ( F_19 ( & V_9 -> V_19 ) == 1 )
F_18 ( V_9 -> V_20 , 1 ) ;
}
static void F_20 ( struct V_8 * V_9 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
T_1 V_2 )
{
if ( V_22 -> V_25 != V_26 )
return;
if ( V_24 -> V_27 * V_24 -> V_28 <= 1024 )
return;
V_9 -> V_29 = V_2 + ( V_24 -> V_27 * V_24 -> V_28 ) - 1024 ;
F_4 ( V_9 -> V_29 , 512 ) ;
}
static void F_21 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_29 )
return;
F_6 ( V_9 -> V_29 , 512 ) ;
V_9 -> V_29 = 0 ;
}
static int F_22 ( struct V_30 * V_31 )
{
struct V_32 * V_33 , * V_34 = V_31 -> V_35 . V_36 ;
struct V_8 * V_9 ;
struct V_37 * V_38 ;
void V_13 * V_17 ;
int V_39 [ 9 ] ;
int V_40 , V_41 = 0 ;
T_1 V_16 ;
V_9 = F_23 ( & V_31 -> V_35 , sizeof( * V_9 ) , V_42 ) ;
if ( ! V_9 )
return - V_43 ;
F_24 ( & V_9 -> V_44 ) ;
F_25 ( & V_9 -> V_15 , 1 ) ;
V_9 -> V_35 = & V_31 -> V_35 ;
V_9 -> V_45 = F_7 ;
V_9 -> V_46 = F_11 ;
V_9 -> V_47 = F_13 ;
V_9 -> V_48 = F_16 ;
if ( F_9 ( V_49 ) ||
F_9 ( V_50 ) ) {
V_9 -> V_51 = F_20 ;
V_9 -> V_52 = F_21 ;
}
V_9 -> V_53 = F_26 () ;
if ( F_27 ( V_34 , L_1 ) ) {
V_9 -> V_54 = true ;
V_9 -> V_55 = true ;
V_9 -> V_10 = true ;
V_9 -> V_56 = true ;
for ( V_40 = 0 ; V_40 < 9 ; V_40 ++ ) {
V_39 [ V_40 ] = F_28 ( V_31 , V_40 ) ;
if ( V_39 [ V_40 ] < 0 )
return V_39 [ V_40 ] ;
F_29 ( V_39 [ V_40 ] , V_57 ) ;
}
} else {
V_9 -> V_54 = false ;
V_9 -> V_55 = false ;
V_9 -> V_10 = false ;
for ( V_40 = 0 ; V_40 < 2 ; V_40 ++ ) {
V_39 [ V_40 ] = F_28 ( V_31 , V_40 ) ;
if ( V_39 [ V_40 ] < 0 )
return V_39 [ V_40 ] ;
}
}
V_9 -> V_58 = - 1 ;
V_38 = F_30 ( V_31 , V_59 , 0 ) ;
if ( ! V_38 ) {
F_31 ( & V_31 -> V_35 , L_2 ) ;
return - V_60 ;
}
V_17 = F_32 ( & V_31 -> V_35 , V_38 ) ;
if ( F_33 ( V_17 ) )
return F_34 ( V_17 ) ;
V_9 -> V_17 = ( void V_13 * ) V_17 ;
V_9 -> V_61 = 0 ;
V_38 = F_30 ( V_31 , V_59 , 1 ) ;
if ( ! V_38 ) {
F_31 ( & V_31 -> V_35 , L_3 ) ;
return - V_62 ;
}
V_17 = F_32 ( & V_31 -> V_35 , V_38 ) ;
if ( F_33 ( V_17 ) )
return F_34 ( V_17 ) ;
V_9 -> V_63 = ( void V_13 * ) V_17 ;
V_9 -> V_64 = - 0x20 ;
V_41 = F_35 ( & V_31 -> V_35 , F_36 ( 64 ) ) ;
if ( V_41 )
return V_41 ;
V_16 = F_37 ( V_9 -> V_17 + F_14 ( V_9 ) ) ;
F_10 ( V_16 , V_9 -> V_17 + F_14 ( V_9 ) ) ;
if ( V_9 -> V_10 ) {
for ( V_40 = 1 ; V_40 <= 4 ; V_40 ++ ) {
V_41 = F_38 ( & V_31 -> V_35 , V_39 [ V_40 ] ,
V_65 ,
0 , V_66 [ V_40 ] , V_9 ) ;
if ( V_41 < 0 ) {
F_31 ( & V_31 -> V_35 , L_4 ,
V_39 [ V_40 ] ) ;
return V_41 ;
}
}
} else {
V_41 = F_38 ( & V_31 -> V_35 , V_39 [ 0 ] ,
V_65 , 0 , V_67 ,
V_9 ) ;
if ( V_41 < 0 ) {
F_31 ( & V_31 -> V_35 , L_4 ,
V_39 [ 0 ] ) ;
return V_41 ;
}
}
V_9 -> V_20 = F_39 ( & V_31 -> V_35 ,
L_5 ,
V_68 ) ;
if ( F_33 ( V_9 -> V_20 ) ) {
F_31 ( & V_31 -> V_35 , L_6 ) ;
return F_34 ( V_9 -> V_20 ) ;
}
F_40 ( V_31 , V_9 ) ;
V_40 = 0 ;
F_41 (node, cn) {
V_9 -> V_69 [ V_40 ] =
F_42 ( V_33 , NULL , & V_31 -> V_35 ) ;
if ( ! V_9 -> V_69 [ V_40 ] ) {
V_40 ++ ;
continue;
}
V_41 = F_43 ( & V_9 -> V_69 [ V_40 ] -> V_35 , V_9 ) ;
if ( V_41 ) {
F_31 ( & V_31 -> V_35 , L_7 ) ;
F_16 ( V_9 , 0 ) ;
goto error;
}
V_40 ++ ;
}
return 0 ;
error:
for ( V_40 = 0 ; V_40 < V_70 ; V_40 ++ ) {
if ( V_9 -> V_71 [ V_40 ] )
F_44 ( V_9 -> V_71 [ V_40 ] ) ;
if ( V_9 -> V_69 [ V_40 ] )
F_45 ( & V_9 -> V_69 [ V_40 ] -> V_35 , NULL ) ;
}
return V_41 ;
}
static int F_46 ( struct V_30 * V_31 )
{
struct V_8 * V_9 = F_47 ( V_31 ) ;
T_1 V_72 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_70 ; V_40 ++ )
if ( V_9 -> V_71 [ V_40 ] )
F_44 ( V_9 -> V_71 [ V_40 ] ) ;
V_72 = F_37 ( V_9 -> V_63 + F_48 ( V_9 ) ) ;
V_72 &= ~ V_73 ;
F_10 ( V_72 , V_9 -> V_63 + F_48 ( V_9 ) ) ;
F_16 ( V_9 , 0 ) ;
return 0 ;
}
