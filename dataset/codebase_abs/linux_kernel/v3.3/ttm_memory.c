static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 (KERN_INFO TTM_PFX
L_1 ,
zone->name, (unsigned long long) zone->used_mem >> 10 ) ;
F_4 ( V_4 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
char * V_7 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
T_2 V_8 = 0 ;
F_6 ( & V_4 -> V_9 -> V_10 ) ;
if ( V_6 == & V_11 )
V_8 = V_4 -> V_12 ;
else if ( V_6 == & V_13 )
V_8 = V_4 -> V_14 ;
else if ( V_6 == & V_15 )
V_8 = V_4 -> V_16 ;
else if ( V_6 == & V_17 )
V_8 = V_4 -> V_18 ;
else if ( V_6 == & V_19 )
V_8 = V_4 -> V_20 ;
F_7 ( & V_4 -> V_9 -> V_10 ) ;
return snprintf ( V_7 , V_21 , L_2 ,
( unsigned long long ) V_8 >> 10 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
const char * V_7 ,
T_3 V_22 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
int V_23 ;
unsigned long V_8 ;
T_2 V_24 ;
V_23 = sscanf ( V_7 , L_3 , & V_8 ) ;
if ( V_23 == 0 )
return V_22 ;
V_24 = V_8 ;
V_24 <<= 10 ;
F_6 ( & V_4 -> V_9 -> V_10 ) ;
if ( V_24 > V_4 -> V_12 )
V_24 = V_4 -> V_12 ;
if ( V_6 == & V_13 ) {
V_4 -> V_14 = V_24 ;
if ( V_4 -> V_16 > V_24 )
V_4 -> V_16 = V_24 ;
} else if ( V_6 == & V_15 ) {
V_4 -> V_16 = V_24 ;
if ( V_4 -> V_14 < V_24 )
V_4 -> V_14 = V_24 ;
} else if ( V_6 == & V_17 )
V_4 -> V_18 = V_24 ;
F_7 ( & V_4 -> V_9 -> V_10 ) ;
F_9 ( V_4 -> V_9 ) ;
return V_22 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_25 * V_9 =
F_2 ( V_2 , struct V_25 , V_2 ) ;
F_4 ( V_9 ) ;
}
static bool F_11 ( struct V_25 * V_9 ,
bool V_26 , T_2 V_27 )
{
unsigned int V_28 ;
struct V_3 * V_4 ;
T_2 V_29 ;
for ( V_28 = 0 ; V_28 < V_9 -> V_30 ; ++ V_28 ) {
V_4 = V_9 -> V_31 [ V_28 ] ;
if ( V_26 )
V_29 = V_4 -> V_18 ;
else if ( F_12 ( V_32 ) )
V_29 = V_4 -> V_14 ;
else
V_29 = V_4 -> V_16 ;
V_29 = ( V_27 > V_29 ) ? 0ULL : V_29 ;
if ( V_4 -> V_20 > V_29 )
return true ;
}
return false ;
}
static void F_13 ( struct V_25 * V_9 , bool V_26 ,
T_2 V_27 )
{
int V_33 ;
struct V_34 * V_35 ;
F_6 ( & V_9 -> V_10 ) ;
if ( V_9 -> V_35 == NULL )
goto V_36;
while ( F_11 ( V_9 , V_26 , V_27 ) ) {
V_35 = V_9 -> V_35 ;
F_7 ( & V_9 -> V_10 ) ;
V_33 = V_35 -> V_37 ( V_35 ) ;
F_6 ( & V_9 -> V_10 ) ;
if ( F_14 ( V_33 != 0 ) )
goto V_36;
}
V_36:
F_7 ( & V_9 -> V_10 ) ;
}
static void F_15 ( struct V_38 * V_39 )
{
struct V_25 * V_9 =
F_2 ( V_39 , struct V_25 , V_39 ) ;
F_13 ( V_9 , true , 0ULL ) ;
}
static int F_16 ( struct V_25 * V_9 ,
const struct V_40 * V_41 )
{
struct V_3 * V_4 = F_17 ( sizeof( * V_4 ) , V_42 ) ;
T_2 V_43 ;
int V_33 ;
if ( F_14 ( ! V_4 ) )
return - V_44 ;
V_43 = V_41 -> V_45 - V_41 -> V_46 ;
V_43 *= V_41 -> V_47 ;
V_4 -> V_48 = L_4 ;
V_4 -> V_12 = V_43 ;
V_4 -> V_16 = V_43 >> 1 ;
V_4 -> V_14 = ( V_43 >> 1 ) + ( V_43 >> 2 ) ;
V_4 -> V_18 = V_4 -> V_16 - ( V_43 >> 3 ) ;
V_4 -> V_20 = 0 ;
V_4 -> V_9 = V_9 ;
V_9 -> V_49 = V_4 ;
V_33 = F_18 (
& V_4 -> V_2 , & V_50 , & V_9 -> V_2 , V_4 -> V_48 ) ;
if ( F_14 ( V_33 != 0 ) ) {
F_19 ( & V_4 -> V_2 ) ;
return V_33 ;
}
V_9 -> V_31 [ V_9 -> V_30 ++ ] = V_4 ;
return 0 ;
}
static int F_20 ( struct V_25 * V_9 ,
const struct V_40 * V_41 )
{
struct V_3 * V_4 ;
T_2 V_43 ;
int V_33 ;
if ( V_41 -> V_46 == 0 )
return 0 ;
V_4 = F_17 ( sizeof( * V_4 ) , V_42 ) ;
if ( F_14 ( ! V_4 ) )
return - V_44 ;
V_43 = V_41 -> V_45 ;
V_43 *= V_41 -> V_47 ;
V_4 -> V_48 = L_5 ;
V_4 -> V_12 = V_43 ;
V_4 -> V_16 = V_43 >> 1 ;
V_4 -> V_14 = ( V_43 >> 1 ) + ( V_43 >> 2 ) ;
V_4 -> V_18 = V_4 -> V_16 - ( V_43 >> 3 ) ;
V_4 -> V_20 = 0 ;
V_4 -> V_9 = V_9 ;
V_9 -> V_51 = V_4 ;
V_33 = F_18 (
& V_4 -> V_2 , & V_50 , & V_9 -> V_2 , V_4 -> V_48 ) ;
if ( F_14 ( V_33 != 0 ) ) {
F_19 ( & V_4 -> V_2 ) ;
return V_33 ;
}
V_9 -> V_31 [ V_9 -> V_30 ++ ] = V_4 ;
return 0 ;
}
static int F_21 ( struct V_25 * V_9 ,
const struct V_40 * V_41 )
{
struct V_3 * V_4 = F_17 ( sizeof( * V_4 ) , V_42 ) ;
T_2 V_43 ;
int V_33 ;
if ( F_14 ( ! V_4 ) )
return - V_44 ;
V_43 = V_41 -> V_45 ;
V_43 *= V_41 -> V_47 ;
if ( V_43 <= ( ( T_2 ) 1ULL << 32 ) ) {
F_4 ( V_4 ) ;
return 0 ;
}
V_43 = ( ( T_2 ) 1ULL << 32 ) ;
V_4 -> V_48 = L_6 ;
V_4 -> V_12 = V_43 ;
V_4 -> V_16 = V_43 >> 1 ;
V_4 -> V_14 = ( V_43 >> 1 ) + ( V_43 >> 2 ) ;
V_4 -> V_18 = V_4 -> V_16 - ( V_43 >> 3 ) ;
V_4 -> V_20 = 0 ;
V_4 -> V_9 = V_9 ;
V_9 -> V_52 = V_4 ;
V_33 = F_18 (
& V_4 -> V_2 , & V_50 , & V_9 -> V_2 , V_4 -> V_48 ) ;
if ( F_14 ( V_33 != 0 ) ) {
F_19 ( & V_4 -> V_2 ) ;
return V_33 ;
}
V_9 -> V_31 [ V_9 -> V_30 ++ ] = V_4 ;
return 0 ;
}
int F_22 ( struct V_25 * V_9 )
{
struct V_40 V_41 ;
int V_33 ;
int V_28 ;
struct V_3 * V_4 ;
F_23 ( & V_9 -> V_10 ) ;
V_9 -> V_53 = F_24 ( L_7 ) ;
F_25 ( & V_9 -> V_39 , F_15 ) ;
F_26 ( & V_9 -> V_54 ) ;
V_33 = F_18 (
& V_9 -> V_2 , & V_55 , F_27 () , L_8 ) ;
if ( F_14 ( V_33 != 0 ) ) {
F_19 ( & V_9 -> V_2 ) ;
return V_33 ;
}
F_28 ( & V_41 ) ;
V_33 = F_16 ( V_9 , & V_41 ) ;
if ( F_14 ( V_33 != 0 ) )
goto V_56;
#ifdef F_29
V_33 = F_20 ( V_9 , & V_41 ) ;
if ( F_14 ( V_33 != 0 ) )
goto V_56;
#else
V_33 = F_21 ( V_9 , & V_41 ) ;
if ( F_14 ( V_33 != 0 ) )
goto V_56;
#endif
for ( V_28 = 0 ; V_28 < V_9 -> V_30 ; ++ V_28 ) {
V_4 = V_9 -> V_31 [ V_28 ] ;
F_3 (KERN_INFO TTM_PFX
L_9 ,
zone->name, (unsigned long long) zone->max_mem >> 10 ) ;
}
F_30 ( V_9 , V_9 -> V_49 -> V_16 / ( 2 * V_21 ) ) ;
F_31 ( V_9 , V_9 -> V_49 -> V_16 / ( 2 * V_21 ) ) ;
return 0 ;
V_56:
F_32 ( V_9 ) ;
return V_33 ;
}
void F_32 ( struct V_25 * V_9 )
{
unsigned int V_28 ;
struct V_3 * V_4 ;
F_33 () ;
F_34 () ;
F_35 ( V_9 -> V_53 ) ;
F_36 ( V_9 -> V_53 ) ;
V_9 -> V_53 = NULL ;
for ( V_28 = 0 ; V_28 < V_9 -> V_30 ; ++ V_28 ) {
V_4 = V_9 -> V_31 [ V_28 ] ;
F_37 ( & V_4 -> V_2 ) ;
F_19 ( & V_4 -> V_2 ) ;
}
F_37 ( & V_9 -> V_2 ) ;
F_19 ( & V_9 -> V_2 ) ;
}
static void F_9 ( struct V_25 * V_9 )
{
bool V_57 = false ;
unsigned int V_28 ;
struct V_3 * V_4 ;
F_6 ( & V_9 -> V_10 ) ;
for ( V_28 = 0 ; V_28 < V_9 -> V_30 ; ++ V_28 ) {
V_4 = V_9 -> V_31 [ V_28 ] ;
if ( V_4 -> V_20 > V_4 -> V_18 ) {
V_57 = true ;
break;
}
}
F_7 ( & V_9 -> V_10 ) ;
if ( F_14 ( V_57 ) )
( void ) F_38 ( V_9 -> V_53 , & V_9 -> V_39 ) ;
}
static void F_39 ( struct V_25 * V_9 ,
struct V_3 * V_58 ,
T_2 V_59 )
{
unsigned int V_28 ;
struct V_3 * V_4 ;
F_6 ( & V_9 -> V_10 ) ;
for ( V_28 = 0 ; V_28 < V_9 -> V_30 ; ++ V_28 ) {
V_4 = V_9 -> V_31 [ V_28 ] ;
if ( V_58 && V_4 != V_58 )
continue;
V_4 -> V_20 -= V_59 ;
}
F_7 ( & V_9 -> V_10 ) ;
}
void F_40 ( struct V_25 * V_9 ,
T_2 V_59 )
{
return F_39 ( V_9 , NULL , V_59 ) ;
}
static int F_41 ( struct V_25 * V_9 ,
struct V_3 * V_58 ,
T_2 V_59 , bool V_60 )
{
T_2 V_61 ;
int V_33 = - V_44 ;
unsigned int V_28 ;
struct V_3 * V_4 ;
F_6 ( & V_9 -> V_10 ) ;
for ( V_28 = 0 ; V_28 < V_9 -> V_30 ; ++ V_28 ) {
V_4 = V_9 -> V_31 [ V_28 ] ;
if ( V_58 && V_4 != V_58 )
continue;
V_61 = ( F_12 ( V_32 ) ) ?
V_4 -> V_14 : V_4 -> V_16 ;
if ( V_4 -> V_20 > V_61 )
goto V_62;
}
if ( V_60 ) {
for ( V_28 = 0 ; V_28 < V_9 -> V_30 ; ++ V_28 ) {
V_4 = V_9 -> V_31 [ V_28 ] ;
if ( V_58 && V_4 != V_58 )
continue;
V_4 -> V_20 += V_59 ;
}
}
V_33 = 0 ;
V_62:
F_7 ( & V_9 -> V_10 ) ;
F_9 ( V_9 ) ;
return V_33 ;
}
static int F_42 ( struct V_25 * V_9 ,
struct V_3 * V_58 ,
T_2 V_63 ,
bool V_64 , bool V_65 )
{
int V_66 = V_67 ;
while ( F_14 ( F_41 ( V_9 ,
V_58 ,
V_63 , true )
!= 0 ) ) {
if ( V_64 )
return - V_44 ;
if ( F_14 ( V_66 -- == 0 ) )
return - V_44 ;
F_13 ( V_9 , false , V_63 + ( V_63 >> 2 ) + 16 ) ;
}
return 0 ;
}
int F_43 ( struct V_25 * V_9 , T_2 V_63 ,
bool V_64 , bool V_65 )
{
return F_42 ( V_9 , NULL , V_63 , V_64 ,
V_65 ) ;
}
int F_44 ( struct V_25 * V_9 ,
struct V_68 * V_68 ,
bool V_64 , bool V_65 )
{
struct V_3 * V_4 = NULL ;
#ifdef F_29
if ( F_45 ( V_68 ) && V_9 -> V_51 != NULL )
V_4 = V_9 -> V_51 ;
#else
if ( V_9 -> V_52 && F_46 ( V_68 ) > 0x00100000UL )
V_4 = V_9 -> V_49 ;
#endif
return F_42 ( V_9 , V_4 , V_21 , V_64 ,
V_65 ) ;
}
void F_47 ( struct V_25 * V_9 , struct V_68 * V_68 )
{
struct V_3 * V_4 = NULL ;
#ifdef F_29
if ( F_45 ( V_68 ) && V_9 -> V_51 != NULL )
V_4 = V_9 -> V_51 ;
#else
if ( V_9 -> V_52 && F_46 ( V_68 ) > 0x00100000UL )
V_4 = V_9 -> V_49 ;
#endif
F_39 ( V_9 , V_4 , V_21 ) ;
}
T_3 F_48 ( T_3 V_22 )
{
if ( ( V_22 & ( V_22 - 1 ) ) == 0 )
return V_22 ;
else if ( V_22 > V_21 )
return F_49 ( V_22 ) ;
else {
T_3 V_69 = 4 ;
while ( V_69 < V_22 )
V_69 <<= 1 ;
return V_69 ;
}
return 0 ;
}
