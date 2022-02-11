static struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 ;
F_2 (e, &tcp_cong_list, list) {
if ( strcmp ( V_3 -> V_2 , V_2 ) == 0 )
return V_3 ;
}
return NULL ;
}
static const struct V_1 * F_3 ( const char * V_2 )
{
const struct V_1 * V_4 = F_1 ( V_2 ) ;
#ifdef F_4
if ( ! V_4 && F_5 ( V_5 ) ) {
F_6 () ;
F_7 ( L_1 , V_2 ) ;
F_8 () ;
V_4 = F_1 ( V_2 ) ;
}
#endif
return V_4 ;
}
struct V_1 * F_9 ( T_1 V_6 )
{
struct V_1 * V_3 ;
F_2 (e, &tcp_cong_list, list) {
if ( V_3 -> V_6 == V_6 )
return V_3 ;
}
return NULL ;
}
int F_10 ( struct V_1 * V_4 )
{
int V_7 = 0 ;
if ( ! V_4 -> V_8 || ! V_4 -> V_9 ) {
F_11 ( L_2 , V_4 -> V_2 ) ;
return - V_10 ;
}
V_4 -> V_6 = F_12 ( V_4 -> V_2 , sizeof( V_4 -> V_2 ) , strlen ( V_4 -> V_2 ) ) ;
F_13 ( & V_11 ) ;
if ( V_4 -> V_6 == V_12 || F_9 ( V_4 -> V_6 ) ) {
F_14 ( L_3 ,
V_4 -> V_2 ) ;
V_7 = - V_13 ;
} else {
F_15 ( & V_4 -> V_14 , & V_15 ) ;
F_16 ( L_4 , V_4 -> V_2 ) ;
}
F_17 ( & V_11 ) ;
return V_7 ;
}
void F_18 ( struct V_1 * V_4 )
{
F_13 ( & V_11 ) ;
F_19 ( & V_4 -> V_14 ) ;
F_17 ( & V_11 ) ;
F_20 () ;
}
T_1 F_21 ( const char * V_2 , bool * V_16 )
{
const struct V_1 * V_4 ;
T_1 V_6 = V_12 ;
F_22 () ;
F_8 () ;
V_4 = F_3 ( V_2 ) ;
if ( V_4 ) {
V_6 = V_4 -> V_6 ;
* V_16 = V_4 -> V_17 & V_18 ;
}
F_6 () ;
return V_6 ;
}
char * F_23 ( T_1 V_6 , char * V_19 )
{
const struct V_1 * V_4 ;
char * V_7 = NULL ;
F_8 () ;
V_4 = F_9 ( V_6 ) ;
if ( V_4 )
V_7 = strncpy ( V_19 , V_4 -> V_2 ,
V_20 ) ;
F_6 () ;
return V_7 ;
}
void F_24 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_25 ( V_22 ) ;
struct V_1 * V_4 ;
F_8 () ;
F_2 (ca, &tcp_cong_list, list) {
if ( F_26 ( F_27 ( V_4 -> V_25 ) ) ) {
V_24 -> V_26 = V_4 ;
goto V_27;
}
}
V_27:
F_6 () ;
if ( V_4 -> V_28 )
memset ( V_24 -> V_29 , 0 , sizeof( V_24 -> V_29 ) ) ;
if ( V_4 -> V_17 & V_18 )
F_28 ( V_22 ) ;
else
F_29 ( V_22 ) ;
}
void F_30 ( struct V_21 * V_22 )
{
const struct V_23 * V_24 = F_25 ( V_22 ) ;
if ( V_24 -> V_26 -> V_30 )
V_24 -> V_26 -> V_30 ( V_22 ) ;
if ( F_31 ( V_22 ) )
F_28 ( V_22 ) ;
else
F_29 ( V_22 ) ;
}
static void F_32 ( struct V_21 * V_22 ,
const struct V_1 * V_4 )
{
struct V_23 * V_24 = F_25 ( V_22 ) ;
F_33 ( V_22 ) ;
V_24 -> V_26 = V_4 ;
V_24 -> V_31 = 1 ;
if ( V_22 -> V_32 != V_33 )
F_30 ( V_22 ) ;
}
void F_33 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_25 ( V_22 ) ;
if ( V_24 -> V_26 -> V_34 )
V_24 -> V_26 -> V_34 ( V_22 ) ;
F_34 ( V_24 -> V_26 -> V_25 ) ;
}
int F_35 ( const char * V_2 )
{
struct V_1 * V_4 ;
int V_7 = - V_35 ;
F_13 ( & V_11 ) ;
V_4 = F_1 ( V_2 ) ;
#ifdef F_4
if ( ! V_4 && F_5 ( V_5 ) ) {
F_17 ( & V_11 ) ;
F_7 ( L_1 , V_2 ) ;
F_13 ( & V_11 ) ;
V_4 = F_1 ( V_2 ) ;
}
#endif
if ( V_4 ) {
V_4 -> V_17 |= V_36 ;
F_36 ( & V_4 -> V_14 , & V_15 ) ;
V_7 = 0 ;
}
F_17 ( & V_11 ) ;
return V_7 ;
}
static int T_2 F_37 ( void )
{
return F_35 ( V_37 ) ;
}
void F_38 ( char * V_38 , T_3 V_39 )
{
struct V_1 * V_4 ;
T_3 V_40 = 0 ;
F_8 () ;
F_2 (ca, &tcp_cong_list, list) {
V_40 += snprintf ( V_38 + V_40 , V_39 - V_40 ,
L_5 ,
V_40 == 0 ? L_6 : L_7 , V_4 -> V_2 ) ;
}
F_6 () ;
}
void F_39 ( char * V_2 )
{
struct V_1 * V_4 ;
F_40 ( F_41 ( & V_15 ) ) ;
F_8 () ;
V_4 = F_42 ( V_15 . V_41 , struct V_1 , V_14 ) ;
strncpy ( V_2 , V_4 -> V_2 , V_20 ) ;
F_6 () ;
}
void F_43 ( char * V_38 , T_3 V_39 )
{
struct V_1 * V_4 ;
T_3 V_40 = 0 ;
* V_38 = '\0' ;
F_8 () ;
F_2 (ca, &tcp_cong_list, list) {
if ( ! ( V_4 -> V_17 & V_36 ) )
continue;
V_40 += snprintf ( V_38 + V_40 , V_39 - V_40 ,
L_5 ,
V_40 == 0 ? L_6 : L_7 , V_4 -> V_2 ) ;
}
F_6 () ;
}
int F_44 ( char * V_42 )
{
struct V_1 * V_4 ;
char * V_43 , * V_44 , * V_2 ;
int V_7 = 0 ;
V_43 = V_44 = F_45 ( V_42 , V_45 ) ;
if ( ! V_44 )
return - V_46 ;
F_13 ( & V_11 ) ;
while ( ( V_2 = F_46 ( & V_44 , L_7 ) ) && * V_2 ) {
V_4 = F_1 ( V_2 ) ;
if ( ! V_4 ) {
V_7 = - V_35 ;
goto V_27;
}
}
F_2 (ca, &tcp_cong_list, list)
V_4 -> V_17 &= ~ V_36 ;
while ( ( V_2 = F_46 ( & V_42 , L_7 ) ) && * V_2 ) {
V_4 = F_1 ( V_2 ) ;
F_47 ( ! V_4 ) ;
if ( V_4 )
V_4 -> V_17 |= V_36 ;
}
V_27:
F_17 ( & V_11 ) ;
F_48 ( V_43 ) ;
return V_7 ;
}
int F_49 ( struct V_21 * V_22 , const char * V_2 )
{
struct V_23 * V_24 = F_25 ( V_22 ) ;
const struct V_1 * V_4 ;
int V_47 = 0 ;
if ( V_24 -> V_48 )
return - V_49 ;
F_8 () ;
V_4 = F_3 ( V_2 ) ;
if ( V_4 == V_24 -> V_26 ) {
V_24 -> V_31 = 1 ;
goto V_27;
}
if ( ! V_4 )
V_47 = - V_35 ;
else if ( ! ( ( V_4 -> V_17 & V_36 ) ||
F_50 ( F_51 ( V_22 ) -> V_50 , V_5 ) ) )
V_47 = - V_49 ;
else if ( ! F_27 ( V_4 -> V_25 ) )
V_47 = - V_51 ;
else
F_32 ( V_22 , V_4 ) ;
V_27:
F_6 () ;
return V_47 ;
}
T_1 F_52 ( struct V_52 * V_53 , T_1 V_54 )
{
T_1 V_55 = F_53 ( V_53 -> V_56 + V_54 , V_53 -> V_57 ) ;
V_54 -= V_55 - V_53 -> V_56 ;
V_53 -> V_56 = F_53 ( V_55 , V_53 -> V_58 ) ;
return V_54 ;
}
void F_54 ( struct V_52 * V_53 , T_1 V_59 , T_1 V_54 )
{
if ( V_53 -> V_60 >= V_59 ) {
V_53 -> V_60 = 0 ;
V_53 -> V_56 ++ ;
}
V_53 -> V_60 += V_54 ;
if ( V_53 -> V_60 >= V_59 ) {
T_1 V_61 = V_53 -> V_60 / V_59 ;
V_53 -> V_60 -= V_61 * V_59 ;
V_53 -> V_56 += V_61 ;
}
V_53 -> V_56 = F_53 ( V_53 -> V_56 , V_53 -> V_58 ) ;
}
void F_55 ( struct V_21 * V_22 , T_1 V_62 , T_1 V_54 )
{
struct V_52 * V_53 = F_56 ( V_22 ) ;
if ( ! F_57 ( V_22 ) )
return;
if ( F_58 ( V_53 ) ) {
V_54 = F_52 ( V_53 , V_54 ) ;
if ( ! V_54 )
return;
}
F_54 ( V_53 , V_53 -> V_56 , V_54 ) ;
}
T_1 F_59 ( struct V_21 * V_22 )
{
const struct V_52 * V_53 = F_56 ( V_22 ) ;
return F_60 ( V_53 -> V_56 >> 1U , 2U ) ;
}
