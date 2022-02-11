static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( L_1 ,
V_4 -> V_5 , ( unsigned long long ) V_4 -> V_6 >> 10 ) ;
F_4 ( V_4 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
char * V_9 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
T_2 V_10 = 0 ;
F_6 ( & V_4 -> V_11 -> V_12 ) ;
if ( V_8 == & V_13 )
V_10 = V_4 -> V_14 ;
else if ( V_8 == & V_15 )
V_10 = V_4 -> V_16 ;
else if ( V_8 == & V_17 )
V_10 = V_4 -> V_18 ;
else if ( V_8 == & V_19 )
V_10 = V_4 -> V_20 ;
else if ( V_8 == & V_21 )
V_10 = V_4 -> V_6 ;
F_7 ( & V_4 -> V_11 -> V_12 ) ;
return snprintf ( V_9 , V_22 , L_2 ,
( unsigned long long ) V_10 >> 10 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
const char * V_9 ,
T_3 V_23 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
int V_24 ;
unsigned long V_10 ;
T_2 V_25 ;
V_24 = sscanf ( V_9 , L_3 , & V_10 ) ;
if ( V_24 == 0 )
return V_23 ;
V_25 = V_10 ;
V_25 <<= 10 ;
F_6 ( & V_4 -> V_11 -> V_12 ) ;
if ( V_25 > V_4 -> V_14 )
V_25 = V_4 -> V_14 ;
if ( V_8 == & V_15 ) {
V_4 -> V_16 = V_25 ;
if ( V_4 -> V_18 > V_25 )
V_4 -> V_18 = V_25 ;
} else if ( V_8 == & V_17 ) {
V_4 -> V_18 = V_25 ;
if ( V_4 -> V_16 < V_25 )
V_4 -> V_16 = V_25 ;
} else if ( V_8 == & V_19 )
V_4 -> V_20 = V_25 ;
F_7 ( & V_4 -> V_11 -> V_12 ) ;
F_9 ( V_4 -> V_11 ) ;
return V_23 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_26 * V_11 =
F_2 ( V_2 , struct V_26 , V_2 ) ;
F_4 ( V_11 ) ;
}
static bool F_11 ( struct V_26 * V_11 ,
bool V_27 , T_2 V_28 )
{
unsigned int V_29 ;
struct V_3 * V_4 ;
T_2 V_30 ;
for ( V_29 = 0 ; V_29 < V_11 -> V_31 ; ++ V_29 ) {
V_4 = V_11 -> V_32 [ V_29 ] ;
if ( V_27 )
V_30 = V_4 -> V_20 ;
else if ( F_12 ( V_33 ) )
V_30 = V_4 -> V_16 ;
else
V_30 = V_4 -> V_18 ;
V_30 = ( V_28 > V_30 ) ? 0ULL : V_30 ;
if ( V_4 -> V_6 > V_30 )
return true ;
}
return false ;
}
static void F_13 ( struct V_26 * V_11 , bool V_27 ,
T_2 V_28 )
{
int V_34 ;
struct V_35 * V_36 ;
F_6 ( & V_11 -> V_12 ) ;
if ( V_11 -> V_36 == NULL )
goto V_37;
while ( F_11 ( V_11 , V_27 , V_28 ) ) {
V_36 = V_11 -> V_36 ;
F_7 ( & V_11 -> V_12 ) ;
V_34 = V_36 -> V_38 ( V_36 ) ;
F_6 ( & V_11 -> V_12 ) ;
if ( F_14 ( V_34 != 0 ) )
goto V_37;
}
V_37:
F_7 ( & V_11 -> V_12 ) ;
}
static void F_15 ( struct V_39 * V_40 )
{
struct V_26 * V_11 =
F_2 ( V_40 , struct V_26 , V_40 ) ;
F_13 ( V_11 , true , 0ULL ) ;
}
static int F_16 ( struct V_26 * V_11 ,
const struct V_41 * V_42 )
{
struct V_3 * V_4 = F_17 ( sizeof( * V_4 ) , V_43 ) ;
T_2 V_44 ;
int V_34 ;
if ( F_14 ( ! V_4 ) )
return - V_45 ;
V_44 = V_42 -> V_46 - V_42 -> V_47 ;
V_44 *= V_42 -> V_48 ;
V_4 -> V_5 = L_4 ;
V_4 -> V_14 = V_44 ;
V_4 -> V_18 = V_44 >> 1 ;
V_4 -> V_16 = ( V_44 >> 1 ) + ( V_44 >> 2 ) ;
V_4 -> V_20 = V_4 -> V_18 - ( V_44 >> 3 ) ;
V_4 -> V_6 = 0 ;
V_4 -> V_11 = V_11 ;
V_11 -> V_49 = V_4 ;
V_34 = F_18 (
& V_4 -> V_2 , & V_50 , & V_11 -> V_2 , V_4 -> V_5 ) ;
if ( F_14 ( V_34 != 0 ) ) {
F_19 ( & V_4 -> V_2 ) ;
return V_34 ;
}
V_11 -> V_32 [ V_11 -> V_31 ++ ] = V_4 ;
return 0 ;
}
static int F_20 ( struct V_26 * V_11 ,
const struct V_41 * V_42 )
{
struct V_3 * V_4 ;
T_2 V_44 ;
int V_34 ;
if ( V_42 -> V_47 == 0 )
return 0 ;
V_4 = F_17 ( sizeof( * V_4 ) , V_43 ) ;
if ( F_14 ( ! V_4 ) )
return - V_45 ;
V_44 = V_42 -> V_46 ;
V_44 *= V_42 -> V_48 ;
V_4 -> V_5 = L_5 ;
V_4 -> V_14 = V_44 ;
V_4 -> V_18 = V_44 >> 1 ;
V_4 -> V_16 = ( V_44 >> 1 ) + ( V_44 >> 2 ) ;
V_4 -> V_20 = V_4 -> V_18 - ( V_44 >> 3 ) ;
V_4 -> V_6 = 0 ;
V_4 -> V_11 = V_11 ;
V_11 -> V_51 = V_4 ;
V_34 = F_18 (
& V_4 -> V_2 , & V_50 , & V_11 -> V_2 , L_6 ,
V_4 -> V_5 ) ;
if ( F_14 ( V_34 != 0 ) ) {
F_19 ( & V_4 -> V_2 ) ;
return V_34 ;
}
V_11 -> V_32 [ V_11 -> V_31 ++ ] = V_4 ;
return 0 ;
}
static int F_21 ( struct V_26 * V_11 ,
const struct V_41 * V_42 )
{
struct V_3 * V_4 = F_17 ( sizeof( * V_4 ) , V_43 ) ;
T_2 V_44 ;
int V_34 ;
if ( F_14 ( ! V_4 ) )
return - V_45 ;
V_44 = V_42 -> V_46 ;
V_44 *= V_42 -> V_48 ;
if ( V_44 <= ( ( T_2 ) 1ULL << 32 ) ) {
F_4 ( V_4 ) ;
return 0 ;
}
V_44 = ( ( T_2 ) 1ULL << 32 ) ;
V_4 -> V_5 = L_7 ;
V_4 -> V_14 = V_44 ;
V_4 -> V_18 = V_44 >> 1 ;
V_4 -> V_16 = ( V_44 >> 1 ) + ( V_44 >> 2 ) ;
V_4 -> V_20 = V_4 -> V_18 - ( V_44 >> 3 ) ;
V_4 -> V_6 = 0 ;
V_4 -> V_11 = V_11 ;
V_11 -> V_52 = V_4 ;
V_34 = F_18 (
& V_4 -> V_2 , & V_50 , & V_11 -> V_2 , V_4 -> V_5 ) ;
if ( F_14 ( V_34 != 0 ) ) {
F_19 ( & V_4 -> V_2 ) ;
return V_34 ;
}
V_11 -> V_32 [ V_11 -> V_31 ++ ] = V_4 ;
return 0 ;
}
int F_22 ( struct V_26 * V_11 )
{
struct V_41 V_42 ;
int V_34 ;
int V_29 ;
struct V_3 * V_4 ;
F_23 ( & V_11 -> V_12 ) ;
V_11 -> V_53 = F_24 ( L_8 ) ;
F_25 ( & V_11 -> V_40 , F_15 ) ;
V_34 = F_18 (
& V_11 -> V_2 , & V_54 , F_26 () , L_9 ) ;
if ( F_14 ( V_34 != 0 ) ) {
F_19 ( & V_11 -> V_2 ) ;
return V_34 ;
}
F_27 ( & V_42 ) ;
V_34 = F_16 ( V_11 , & V_42 ) ;
if ( F_14 ( V_34 != 0 ) )
goto V_55;
#ifdef F_28
V_34 = F_20 ( V_11 , & V_42 ) ;
if ( F_14 ( V_34 != 0 ) )
goto V_55;
#else
V_34 = F_21 ( V_11 , & V_42 ) ;
if ( F_14 ( V_34 != 0 ) )
goto V_55;
#endif
for ( V_29 = 0 ; V_29 < V_11 -> V_31 ; ++ V_29 ) {
V_4 = V_11 -> V_32 [ V_29 ] ;
F_3 ( L_10 ,
V_4 -> V_5 , ( unsigned long long ) V_4 -> V_18 >> 10 ) ;
}
F_29 ( V_11 , V_11 -> V_49 -> V_18 / ( 2 * V_22 ) ) ;
F_30 ( V_11 , V_11 -> V_49 -> V_18 / ( 2 * V_22 ) ) ;
return 0 ;
V_55:
F_31 ( V_11 ) ;
return V_34 ;
}
void F_31 ( struct V_26 * V_11 )
{
unsigned int V_29 ;
struct V_3 * V_4 ;
F_32 () ;
F_33 () ;
F_34 ( V_11 -> V_53 ) ;
F_35 ( V_11 -> V_53 ) ;
V_11 -> V_53 = NULL ;
for ( V_29 = 0 ; V_29 < V_11 -> V_31 ; ++ V_29 ) {
V_4 = V_11 -> V_32 [ V_29 ] ;
F_36 ( & V_4 -> V_2 ) ;
F_19 ( & V_4 -> V_2 ) ;
}
F_36 ( & V_11 -> V_2 ) ;
F_19 ( & V_11 -> V_2 ) ;
}
static void F_9 ( struct V_26 * V_11 )
{
bool V_56 = false ;
unsigned int V_29 ;
struct V_3 * V_4 ;
F_6 ( & V_11 -> V_12 ) ;
for ( V_29 = 0 ; V_29 < V_11 -> V_31 ; ++ V_29 ) {
V_4 = V_11 -> V_32 [ V_29 ] ;
if ( V_4 -> V_6 > V_4 -> V_20 ) {
V_56 = true ;
break;
}
}
F_7 ( & V_11 -> V_12 ) ;
if ( F_14 ( V_56 ) )
( void ) F_37 ( V_11 -> V_53 , & V_11 -> V_40 ) ;
}
static void F_38 ( struct V_26 * V_11 ,
struct V_3 * V_57 ,
T_2 V_58 )
{
unsigned int V_29 ;
struct V_3 * V_4 ;
F_6 ( & V_11 -> V_12 ) ;
for ( V_29 = 0 ; V_29 < V_11 -> V_31 ; ++ V_29 ) {
V_4 = V_11 -> V_32 [ V_29 ] ;
if ( V_57 && V_4 != V_57 )
continue;
V_4 -> V_6 -= V_58 ;
}
F_7 ( & V_11 -> V_12 ) ;
}
void F_39 ( struct V_26 * V_11 ,
T_2 V_58 )
{
return F_38 ( V_11 , NULL , V_58 ) ;
}
static int F_40 ( struct V_26 * V_11 ,
struct V_3 * V_57 ,
T_2 V_58 , bool V_59 )
{
T_2 V_60 ;
int V_34 = - V_45 ;
unsigned int V_29 ;
struct V_3 * V_4 ;
F_6 ( & V_11 -> V_12 ) ;
for ( V_29 = 0 ; V_29 < V_11 -> V_31 ; ++ V_29 ) {
V_4 = V_11 -> V_32 [ V_29 ] ;
if ( V_57 && V_4 != V_57 )
continue;
V_60 = ( F_12 ( V_33 ) ) ?
V_4 -> V_16 : V_4 -> V_18 ;
if ( V_4 -> V_6 > V_60 )
goto V_61;
}
if ( V_59 ) {
for ( V_29 = 0 ; V_29 < V_11 -> V_31 ; ++ V_29 ) {
V_4 = V_11 -> V_32 [ V_29 ] ;
if ( V_57 && V_4 != V_57 )
continue;
V_4 -> V_6 += V_58 ;
}
}
V_34 = 0 ;
V_61:
F_7 ( & V_11 -> V_12 ) ;
F_9 ( V_11 ) ;
return V_34 ;
}
static int F_41 ( struct V_26 * V_11 ,
struct V_3 * V_57 ,
T_2 V_62 ,
bool V_63 , bool V_64 )
{
int V_65 = V_66 ;
while ( F_14 ( F_40 ( V_11 ,
V_57 ,
V_62 , true )
!= 0 ) ) {
if ( V_63 )
return - V_45 ;
if ( F_14 ( V_65 -- == 0 ) )
return - V_45 ;
F_13 ( V_11 , false , V_62 + ( V_62 >> 2 ) + 16 ) ;
}
return 0 ;
}
int F_42 ( struct V_26 * V_11 , T_2 V_62 ,
bool V_63 , bool V_64 )
{
return F_41 ( V_11 , NULL , V_62 , V_63 ,
V_64 ) ;
}
int F_43 ( struct V_26 * V_11 ,
struct V_67 * V_67 ,
bool V_63 , bool V_64 )
{
struct V_3 * V_4 = NULL ;
#ifdef F_28
if ( F_44 ( V_67 ) && V_11 -> V_51 != NULL )
V_4 = V_11 -> V_51 ;
#else
if ( V_11 -> V_52 && F_45 ( V_67 ) > 0x00100000UL )
V_4 = V_11 -> V_49 ;
#endif
return F_41 ( V_11 , V_4 , V_22 , V_63 ,
V_64 ) ;
}
void F_46 ( struct V_26 * V_11 , struct V_67 * V_67 )
{
struct V_3 * V_4 = NULL ;
#ifdef F_28
if ( F_44 ( V_67 ) && V_11 -> V_51 != NULL )
V_4 = V_11 -> V_51 ;
#else
if ( V_11 -> V_52 && F_45 ( V_67 ) > 0x00100000UL )
V_4 = V_11 -> V_49 ;
#endif
F_38 ( V_11 , V_4 , V_22 ) ;
}
T_3 F_47 ( T_3 V_23 )
{
if ( ( V_23 & ( V_23 - 1 ) ) == 0 )
return V_23 ;
else if ( V_23 > V_22 )
return F_48 ( V_23 ) ;
else {
T_3 V_68 = 4 ;
while ( V_68 < V_23 )
V_68 <<= 1 ;
return V_68 ;
}
return 0 ;
}
T_2 F_49 ( struct V_26 * V_11 )
{
return V_11 -> V_49 -> V_18 ;
}
