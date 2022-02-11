static void F_1 ( struct V_1 V_2 [ V_3 ] [ V_4 ] )
{
unsigned int V_5 , V_6 ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
V_2 [ V_5 ] [ V_6 ] . V_7 = 0xFFFFFFFF ;
V_2 [ V_5 ] [ V_6 ] . V_8 = 0 ;
V_2 [ V_5 ] [ V_6 ] . V_9 = 0 ;
V_2 [ V_5 ] [ V_6 ] . V_10 = 0 ;
}
}
}
static void F_2 ( struct V_1 * V_2 , unsigned int V_11 )
{
V_2 -> V_10 ++ ;
V_2 -> V_9 += V_11 ;
if ( V_11 < V_2 -> V_7 )
V_2 -> V_7 = V_11 ;
if ( V_11 > V_2 -> V_8 )
V_2 -> V_8 = V_11 ;
}
static void F_3 ( struct V_1 V_2 [ V_3 ] [ V_4 ] )
{
unsigned int V_5 , V_6 ;
T_1 V_12 ;
for ( V_5 = V_13 ; V_5 < V_3 ; V_5 ++ ) {
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
if ( V_2 [ V_5 ] [ V_6 ] . V_10 > 0 ) {
V_12 = ( T_1 ) V_2 [ V_5 ] [ V_6 ] . V_9 ;
F_4 ( V_12 , V_2 [ V_5 ] [ V_6 ] . V_10 ) ;
F_5 ( L_1 ,
V_14 [ V_5 ] . V_15 , V_14 [ V_5 ] . V_16 [ V_6 ] ,
V_2 [ V_5 ] [ V_6 ] . V_7 , ( int ) V_12 , V_2 [ V_5 ] [ V_6 ] . V_8 , ( long long ) V_2 [ V_5 ] [ V_6 ] . V_9 , V_2 [ V_5 ] [ V_6 ] . V_10 ) ;
}
}
}
}
static T_2 F_6 ( struct V_17 * V_18 ,
struct V_19 * V_20 , const char * V_21 , T_3 V_10 )
{
F_1 ( V_22 ) ;
return V_10 ;
}
static T_2 F_7 ( struct V_17 * V_18 ,
struct V_19 * V_20 , const char * V_21 , T_3 V_10 )
{
F_1 ( V_23 ) ;
return V_10 ;
}
static T_2 F_8 ( struct V_17 * V_18 ,
struct V_19 * V_20 , char * V_21 )
{
int V_5 , V_6 ;
char line [ 512 ] ;
T_4 V_24 , V_25 ;
T_1 V_12 ;
T_2 V_26 , V_27 = 0 ;
V_26 = F_9 ( V_21 , V_28 ,
L_2 ) ;
if ( V_26 < 0 )
return V_26 ;
for ( V_5 = V_13 ; V_5 < V_3 ; V_5 ++ ) {
for ( V_6 = 0 ; V_6 < V_4 - 1 ; V_6 ++ ) {
if ( V_22 [ V_5 ] [ V_6 ] . V_10 > 0 ) {
V_12 = ( T_1 ) V_22 [ V_5 ] [ V_6 ] . V_9 ;
F_4 ( V_12 , V_22 [ V_5 ] [ V_6 ] . V_10 ) ;
V_24 = V_22 [ V_5 ] [ V_6 ] . V_7 ;
V_25 = V_22 [ V_5 ] [ V_6 ] . V_8 ;
} else {
V_12 = V_24 = V_25 = 0 ;
}
V_27 = F_9 ( line , 512 ,
L_3 ,
V_14 [ V_5 ] . V_15 ,
V_14 [ V_5 ] . V_16 [ V_6 ] ,
V_24 , ( unsigned int ) V_12 , V_25 ,
V_22 [ V_5 ] [ V_6 ] . V_10 ) ;
if ( V_27 < 0 )
return V_26 ;
if ( V_26 + V_27 >= V_28 )
return V_26 ;
V_26 += V_27 ;
strncat ( V_21 , line , 512 ) ;
}
}
return V_26 ;
}
static T_2 F_10 ( struct V_17 * V_18 ,
struct V_19 * V_20 , char * V_21 )
{
int V_5 ;
char line [ 256 ] ;
T_4 V_24 , V_25 ;
T_1 V_12 ;
T_2 V_26 , V_27 = 0 ;
V_26 = F_9 ( V_21 , V_28 ,
L_4 ) ;
if ( V_26 < 0 )
return V_26 ;
for ( V_5 = V_13 ; V_5 < V_3 ; V_5 ++ ) {
if ( V_23 [ V_5 ] [ V_29 ] . V_10 > 0 ) {
V_12 = ( T_1 ) V_23 [ V_5 ] [ V_29 ] . V_9 ;
F_4 ( V_12 , V_23 [ V_5 ] [ V_29 ] . V_10 ) ;
V_24 = V_23 [ V_5 ] [ V_29 ] . V_7 ;
V_25 = V_23 [ V_5 ] [ V_29 ] . V_8 ;
} else {
V_12 = V_24 = V_25 = 0 ;
}
V_27 = F_9 ( line , 256 ,
L_5 ,
V_14 [ V_5 ] . V_15 ,
V_24 ,
( unsigned int ) V_12 ,
V_25 ,
V_23 [ V_5 ] [ V_29 ] . V_10 ) ;
if ( V_27 < 0 )
return V_26 ;
if ( V_26 + V_27 >= V_28 )
return V_26 ;
V_26 += V_27 ;
strncat ( V_21 , line , 256 ) ;
}
return V_26 ;
}
void F_11 ( unsigned int V_30 , unsigned int V_31 , T_5 V_11 )
{
unsigned long V_32 ;
F_12 ( & V_33 , V_32 ) ;
F_2 ( & ( V_22 [ V_30 ] [ V_31 ] ) , ( unsigned int ) V_11 ) ;
F_13 ( & V_33 , V_32 ) ;
}
void F_14 (
unsigned int V_30 ,
unsigned int V_31 ,
unsigned int V_34 )
{
F_2 ( & ( V_23 [ V_30 ] [ V_31 ] ) , V_34 ) ;
}
void F_15 ( void )
{
F_5 ( L_6 ) ;
F_3 ( V_22 ) ;
F_5 ( L_7 ) ;
F_3 ( V_23 ) ;
}
static T_2 F_16 ( struct V_17 * V_18 ,
struct V_19 * V_20 , char * V_21 )
{
struct V_35 * V_36 = F_17 () ;
T_4 V_37 ;
void T_6 * V_38 = V_36 -> V_38 ;
int V_39 = 0 ;
V_37 = F_18 ( F_19 ( V_40 , V_41 ) ) ;
V_39 += F_9 ( V_21 + V_39 , V_28 - V_39 , L_8 , L_9 , V_42 , V_37 ) ;
V_37 = F_18 ( F_19 ( V_40 , V_43 ) ) ;
V_39 += F_9 ( V_21 + V_39 , V_28 - V_39 , L_8 , L_10 , V_44 , V_37 ) ;
V_37 = F_18 ( F_19 ( V_40 , V_45 ) ) ;
V_39 += F_9 ( V_21 + V_39 , V_28 - V_39 , L_8 , L_11 , V_46 , V_37 ) ;
V_37 = F_18 ( F_19 ( V_47 , V_48 ) ) ;
V_39 += F_9 ( V_21 + V_39 , V_28 - V_39 , L_8 , L_12 , V_49 , V_37 ) ;
V_37 = F_18 ( F_19 ( V_47 , V_50 ) ) ;
V_39 += F_9 ( V_21 + V_39 , V_28 - V_39 , L_8 , L_13 , V_51 , V_37 ) ;
return V_39 ;
}
static T_2 F_20 ( struct V_17 * V_18 ,
struct V_19 * V_20 , char * V_21 )
{
char * V_52 [] = {
L_14 , L_15 ,
#if V_53 V_54
L_16 , L_17 ,
L_18 , L_19 ,
L_20 , L_21 ,
L_22 , L_23 ,
#endif
} ;
int V_5 = 0 , V_39 = 0 ;
V_39 += F_9 ( V_21 + V_39 , V_28 - V_39 , L_24 ) ;
for ( V_5 = 0 ; V_5 < F_21 ( V_52 ) ; V_5 += 2 ) {
V_39 += F_9 ( V_21 + V_39 , V_28 - V_39 , L_25 , V_52 [ V_5 ] , V_52 [ V_5 + 1 ] ) ;
}
return V_39 ;
}
static struct V_35 * F_17 ( void )
{
return V_55 . V_36 ;
}
static int F_22 ( struct V_56 * V_56 , struct V_35 * V_36 ,
struct V_17 * V_57 , const char * V_58 ,
struct V_19 * V_59 , T_4 V_60 )
{
int V_5 ;
memset ( V_56 , 0 , sizeof( struct V_56 ) ) ;
V_56 -> V_36 = V_36 ;
V_56 -> V_61 =
F_23 ( V_58 , V_57 ) ;
if ( ! ( V_56 -> V_61 ) )
return - V_62 ;
V_56 -> V_63 =
F_24 ( sizeof( struct V_64 * ) * ( V_60 + 1 ) ,
V_65 ) ;
if ( ! ( V_56 -> V_63 ) ) {
F_25 ( V_56 -> V_61 ) ;
return - V_62 ;
}
V_56 -> V_60 = V_60 ;
for ( V_5 = 0 ; V_5 < V_60 ; ++ V_5 )
V_56 -> V_63 [ V_5 ] = & ( V_59 [ V_5 ] . V_20 ) ;
V_56 -> V_63 [ V_60 ] = NULL ;
V_56 -> V_66 . V_59 = V_56 -> V_63 ;
return F_26 ( V_56 -> V_61 ,
& ( V_56 -> V_66 ) ) ;
}
static void F_27 ( struct V_56 * V_56 )
{
if ( ! V_56 )
return;
F_28 ( V_56 -> V_63 ) ;
if ( V_56 -> V_61 != NULL )
F_25 ( V_56 -> V_61 ) ;
}
int F_29 ( struct V_17 * V_67 , struct V_35 * V_36 )
{
int V_68 ;
#if V_53 V_54
F_1 ( V_22 ) ;
F_1 ( V_23 ) ;
#endif
F_5 ( L_26 , V_67 -> V_69 ) ;
V_68 = F_22 ( & V_55 , V_36 , V_67 ,
L_27 , V_70 ,
F_21 ( V_70 ) ) ;
return V_68 ;
}
void F_30 ( void )
{
F_27 ( & V_55 ) ;
}
