void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ,
V_7 ) ;
struct V_5 * V_8 = F_2 ( V_4 ,
V_9 ) ;
if ( V_2 -> V_10 )
V_6 -> V_11 =
V_6 -> V_12 = V_2 -> V_10 ;
if ( V_2 -> V_13 )
V_8 -> V_11 =
V_8 -> V_12 = V_2 -> V_13 ;
}
void F_3 ( struct V_14 * V_15 , char * V_16 ,
struct V_1 * V_2 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
char V_20 [ 128 ] ;
if ( ! V_16 )
V_16 = L_1 ;
snprintf ( V_20 , sizeof( V_20 ) , L_2 , V_16 , L_3 ) ;
F_4 ( V_18 , V_20 , & V_2 -> V_10 ) ;
snprintf ( V_20 , sizeof( V_20 ) , L_2 , V_16 , L_4 ) ;
F_4 ( V_18 , V_20 , & V_2 -> V_13 ) ;
F_5 ( V_15 , L_5 , V_2 -> V_10 ) ;
F_5 ( V_15 , L_6 , V_2 -> V_13 ) ;
}
int F_6 ( struct V_14 * V_15 ,
struct V_17 * V_21 ,
struct V_17 * V_22 ,
char * V_16 ,
unsigned int * V_23 )
{
struct V_17 * V_24 = NULL ;
struct V_17 * V_25 = NULL ;
unsigned int V_26 ;
V_26 = F_7 ( V_21 , V_16 ,
& V_24 , & V_25 ) ;
V_26 &= ~ V_27 ;
if ( ! V_24 && ! V_25 ) {
F_5 ( V_15 , L_7 ) ;
V_26 = F_7 ( V_22 , NULL , NULL , NULL ) |
( V_26 & ~ V_28 ) ;
} else {
if ( V_22 == V_24 )
V_26 |= ( V_22 == V_25 ) ?
V_29 : V_30 ;
else
V_26 |= ( V_22 == V_25 ) ?
V_31 : V_32 ;
}
F_8 ( V_24 ) ;
F_8 ( V_25 ) ;
* V_23 = V_26 ;
F_5 ( V_15 , L_8 , V_26 ) ;
return 0 ;
}
int F_9 ( struct V_14 * V_15 ,
struct V_33 * V_34 ,
const char * V_35 , ... )
{
T_1 V_36 ;
char * V_37 = NULL ;
int V_38 = - V_39 ;
va_start ( V_36 , V_35 ) ;
V_37 = F_10 ( V_15 , V_40 , V_35 , V_36 ) ;
va_end ( V_36 ) ;
if ( V_37 ) {
V_38 = 0 ;
V_34 -> V_37 = V_37 ;
V_34 -> V_41 = V_37 ;
F_5 ( V_15 , L_9 , V_37 ) ;
}
return V_38 ;
}
int F_11 ( struct V_42 * V_43 ,
char * V_16 )
{
int V_38 ;
if ( ! V_16 )
V_16 = L_1 ;
V_38 = F_12 ( V_43 , L_10 ) ;
if ( V_38 < 0 || ! V_43 -> V_37 ) {
char V_20 [ 128 ] ;
snprintf ( V_20 , sizeof( V_20 ) , L_11 , V_16 ) ;
V_38 = F_12 ( V_43 , V_20 ) ;
if ( V_38 < 0 )
return V_38 ;
}
if ( ! V_43 -> V_37 && V_43 -> V_34 )
V_43 -> V_37 = V_43 -> V_34 -> V_37 ;
F_5 ( V_43 -> V_15 , L_12 , V_43 -> V_37 ? V_43 -> V_37 : L_1 ) ;
return 0 ;
}
static void F_13 ( struct V_44 * V_45 ,
struct V_46 * V_46 )
{
V_45 -> V_46 = V_46 ;
}
int F_14 ( struct V_44 * V_45 )
{
return F_15 ( V_45 -> V_46 ) ;
}
void F_16 ( struct V_44 * V_45 )
{
F_17 ( V_45 -> V_46 ) ;
}
int F_18 ( struct V_14 * V_15 ,
struct V_17 * V_21 ,
struct V_17 * V_47 ,
struct V_44 * V_48 ,
const char * V_37 )
{
struct V_46 * V_46 ;
T_2 V_49 ;
V_46 = F_19 ( V_15 , V_21 , NULL ) ;
if ( ! F_20 ( V_46 ) ) {
V_48 -> V_50 = F_21 ( V_46 ) ;
F_13 ( V_48 , V_46 ) ;
} else if ( ! F_4 ( V_21 , L_13 , & V_49 ) ) {
V_48 -> V_50 = V_49 ;
} else {
V_46 = F_19 ( V_15 , V_47 , NULL ) ;
if ( ! F_20 ( V_46 ) )
V_48 -> V_50 = F_21 ( V_46 ) ;
}
F_5 ( V_15 , L_14 , V_37 , V_48 -> V_50 ) ;
return 0 ;
}
int F_22 ( struct V_17 * V_21 ,
struct V_17 * * V_47 ,
const char * * V_51 ,
const char * V_52 ,
const char * V_53 ,
int * V_54 )
{
struct V_55 args ;
int V_38 ;
if ( ! V_21 )
return 0 ;
V_38 = F_23 ( V_21 , V_52 , V_53 , 0 , & args ) ;
if ( V_38 )
return V_38 ;
if ( V_51 ) {
V_38 = F_24 ( V_21 , V_51 ) ;
if ( V_38 < 0 )
return V_38 ;
}
* V_47 = args . V_18 ;
if ( V_54 )
* V_54 = ! args . V_56 ;
return 0 ;
}
static int F_25 ( struct V_17 * V_57 )
{
struct V_17 * V_21 ;
struct V_17 * V_58 ;
int V_59 , V_60 ;
int V_38 ;
V_38 = F_26 ( V_57 ) ;
if ( V_38 != - V_61 )
return V_38 ;
V_21 = F_27 ( V_57 ) ;
V_59 = 0 ;
V_60 = - 1 ;
F_28 (node, endpoint) {
if ( V_58 == V_57 )
V_60 = V_59 ;
V_59 ++ ;
}
F_8 ( V_21 ) ;
if ( V_60 < 0 )
return - V_62 ;
return V_60 ;
}
int F_29 ( struct V_17 * V_57 ,
struct V_17 * * V_47 ,
const char * * V_51 )
{
struct V_17 * V_21 ;
struct V_55 args ;
int V_38 ;
if ( ! V_57 )
return 0 ;
if ( ! V_51 )
return 0 ;
V_21 = F_27 ( V_57 ) ;
args . V_18 = V_21 ;
args . args [ 0 ] = F_25 ( V_57 ) ;
args . V_56 = ( F_30 ( V_21 ) > 1 ) ;
V_38 = F_31 ( & args , V_51 ) ;
if ( V_38 < 0 )
return V_38 ;
* V_47 = V_21 ;
return 0 ;
}
int F_32 ( struct V_63 * V_45 ,
struct V_44 * V_48 )
{
int V_38 ;
if ( V_48 -> V_50 ) {
V_38 = F_33 ( V_45 , 0 , V_48 -> V_50 , 0 ) ;
if ( V_38 && V_38 != - V_61 ) {
F_34 ( V_45 -> V_15 , L_15 ) ;
return V_38 ;
}
}
if ( V_48 -> V_64 ) {
V_38 = F_35 ( V_45 ,
V_48 -> V_65 ,
V_48 -> V_66 ,
V_48 -> V_64 ,
V_48 -> V_67 ) ;
if ( V_38 && V_38 != - V_61 ) {
F_34 ( V_45 -> V_15 , L_16 ) ;
return V_38 ;
}
}
return 0 ;
}
int F_36 ( struct V_33 * V_34 )
{
if ( ! V_34 -> V_68 )
V_34 -> V_68 = V_34 -> V_69 ;
return 0 ;
}
void F_37 ( struct V_33 * V_34 ,
int V_70 )
{
if ( V_70 )
V_34 -> V_71 = NULL ;
}
int F_38 ( struct V_42 * V_43 )
{
struct V_33 * V_34 ;
int V_72 ;
for ( V_72 = 0 , V_34 = V_43 -> V_34 ;
V_72 < V_43 -> V_72 ;
V_72 ++ , V_34 ++ ) {
F_8 ( V_34 -> V_69 ) ;
F_8 ( V_34 -> V_73 ) ;
}
return 0 ;
}
int F_39 ( struct V_42 * V_43 ,
char * V_16 ,
int V_74 )
{
struct V_17 * V_21 = V_43 -> V_15 -> V_19 ;
char V_20 [ 128 ] ;
if ( ! V_16 )
V_16 = L_1 ;
snprintf ( V_20 , sizeof( V_20 ) , L_2 , V_16 , L_17 ) ;
if ( ! F_40 ( V_21 , V_20 ) ) {
if ( V_74 )
return 0 ;
return - V_75 ;
}
return F_41 ( V_43 , V_20 ) ;
}
int F_42 ( struct V_42 * V_43 ,
char * V_16 )
{
struct V_17 * V_21 = V_43 -> V_15 -> V_19 ;
char V_20 [ 128 ] ;
if ( ! V_16 )
V_16 = L_1 ;
snprintf ( V_20 , sizeof( V_20 ) , L_2 , V_16 , L_18 ) ;
if ( F_40 ( V_21 , V_20 ) )
return F_43 ( V_43 , V_20 ) ;
return 0 ;
}
