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
T_1 F_21 ( const char * V_2 )
{
const struct V_1 * V_4 ;
T_1 V_6 ;
F_22 () ;
F_8 () ;
V_4 = F_3 ( V_2 ) ;
V_6 = V_4 ? V_4 -> V_6 : V_12 ;
F_6 () ;
return V_6 ;
}
char * F_23 ( T_1 V_6 , char * V_16 )
{
const struct V_1 * V_4 ;
char * V_7 = NULL ;
F_8 () ;
V_4 = F_9 ( V_6 ) ;
if ( V_4 )
V_7 = strncpy ( V_16 , V_4 -> V_2 ,
V_17 ) ;
F_6 () ;
return V_7 ;
}
void F_24 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_25 ( V_19 ) ;
struct V_1 * V_4 ;
F_8 () ;
F_2 (ca, &tcp_cong_list, list) {
if ( F_26 ( F_27 ( V_4 -> V_22 ) ) ) {
V_21 -> V_23 = V_4 ;
goto V_24;
}
}
V_24:
F_6 () ;
if ( V_4 -> V_25 )
memset ( V_21 -> V_26 , 0 , sizeof( V_21 -> V_26 ) ) ;
}
void F_28 ( struct V_18 * V_19 )
{
const struct V_20 * V_21 = F_25 ( V_19 ) ;
if ( V_21 -> V_23 -> V_27 )
V_21 -> V_23 -> V_27 ( V_19 ) ;
}
static void F_29 ( struct V_18 * V_19 ,
const struct V_1 * V_4 )
{
struct V_20 * V_21 = F_25 ( V_19 ) ;
F_30 ( V_19 ) ;
V_21 -> V_23 = V_4 ;
if ( V_19 -> V_28 != V_29 && V_21 -> V_23 -> V_27 )
V_21 -> V_23 -> V_27 ( V_19 ) ;
}
void F_30 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_25 ( V_19 ) ;
if ( V_21 -> V_23 -> V_30 )
V_21 -> V_23 -> V_30 ( V_19 ) ;
F_31 ( V_21 -> V_23 -> V_22 ) ;
}
int F_32 ( const char * V_2 )
{
struct V_1 * V_4 ;
int V_7 = - V_31 ;
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
V_4 -> V_32 |= V_33 ;
F_33 ( & V_4 -> V_14 , & V_15 ) ;
V_7 = 0 ;
}
F_17 ( & V_11 ) ;
return V_7 ;
}
static int T_2 F_34 ( void )
{
return F_32 ( V_34 ) ;
}
void F_35 ( char * V_35 , T_3 V_36 )
{
struct V_1 * V_4 ;
T_3 V_37 = 0 ;
F_8 () ;
F_2 (ca, &tcp_cong_list, list) {
V_37 += snprintf ( V_35 + V_37 , V_36 - V_37 ,
L_5 ,
V_37 == 0 ? L_6 : L_7 , V_4 -> V_2 ) ;
}
F_6 () ;
}
void F_36 ( char * V_2 )
{
struct V_1 * V_4 ;
F_37 ( F_38 ( & V_15 ) ) ;
F_8 () ;
V_4 = F_39 ( V_15 . V_38 , struct V_1 , V_14 ) ;
strncpy ( V_2 , V_4 -> V_2 , V_17 ) ;
F_6 () ;
}
void F_40 ( char * V_35 , T_3 V_36 )
{
struct V_1 * V_4 ;
T_3 V_37 = 0 ;
* V_35 = '\0' ;
F_8 () ;
F_2 (ca, &tcp_cong_list, list) {
if ( ! ( V_4 -> V_32 & V_33 ) )
continue;
V_37 += snprintf ( V_35 + V_37 , V_36 - V_37 ,
L_5 ,
V_37 == 0 ? L_6 : L_7 , V_4 -> V_2 ) ;
}
F_6 () ;
}
int F_41 ( char * V_39 )
{
struct V_1 * V_4 ;
char * V_40 , * V_41 , * V_2 ;
int V_7 = 0 ;
V_40 = V_41 = F_42 ( V_39 , V_42 ) ;
if ( ! V_41 )
return - V_43 ;
F_13 ( & V_11 ) ;
while ( ( V_2 = F_43 ( & V_41 , L_7 ) ) && * V_2 ) {
V_4 = F_1 ( V_2 ) ;
if ( ! V_4 ) {
V_7 = - V_31 ;
goto V_24;
}
}
F_2 (ca, &tcp_cong_list, list)
V_4 -> V_32 &= ~ V_33 ;
while ( ( V_2 = F_43 ( & V_39 , L_7 ) ) && * V_2 ) {
V_4 = F_1 ( V_2 ) ;
F_44 ( ! V_4 ) ;
if ( V_4 )
V_4 -> V_32 |= V_33 ;
}
V_24:
F_17 ( & V_11 ) ;
F_45 ( V_40 ) ;
return V_7 ;
}
int F_46 ( struct V_18 * V_19 , const char * V_2 )
{
struct V_20 * V_21 = F_25 ( V_19 ) ;
const struct V_1 * V_4 ;
int V_44 = 0 ;
if ( V_21 -> V_45 )
return - V_46 ;
F_8 () ;
V_4 = F_3 ( V_2 ) ;
if ( V_4 == V_21 -> V_23 )
goto V_24;
if ( ! V_4 )
V_44 = - V_31 ;
else if ( ! ( ( V_4 -> V_32 & V_33 ) ||
F_47 ( F_48 ( V_19 ) -> V_47 , V_5 ) ) )
V_44 = - V_46 ;
else if ( ! F_27 ( V_4 -> V_22 ) )
V_44 = - V_48 ;
else
F_29 ( V_19 , V_4 ) ;
V_24:
F_6 () ;
return V_44 ;
}
T_1 F_49 ( struct V_49 * V_50 , T_1 V_51 )
{
T_1 V_52 = V_50 -> V_53 + V_51 ;
if ( V_52 > V_50 -> V_54 )
V_52 = V_50 -> V_54 + 1 ;
V_51 -= V_52 - V_50 -> V_53 ;
V_50 -> V_53 = F_50 ( V_52 , V_50 -> V_55 ) ;
return V_51 ;
}
void F_51 ( struct V_49 * V_50 , T_1 V_56 , T_1 V_51 )
{
if ( V_50 -> V_57 >= V_56 ) {
V_50 -> V_57 = 0 ;
V_50 -> V_53 ++ ;
}
V_50 -> V_57 += V_51 ;
if ( V_50 -> V_57 >= V_56 ) {
T_1 V_58 = V_50 -> V_57 / V_56 ;
V_50 -> V_57 -= V_58 * V_56 ;
V_50 -> V_53 += V_58 ;
}
V_50 -> V_53 = F_50 ( V_50 -> V_53 , V_50 -> V_55 ) ;
}
void F_52 ( struct V_18 * V_19 , T_1 V_59 , T_1 V_51 )
{
struct V_49 * V_50 = F_53 ( V_19 ) ;
if ( ! F_54 ( V_19 ) )
return;
if ( V_50 -> V_53 <= V_50 -> V_54 ) {
V_51 = F_49 ( V_50 , V_51 ) ;
if ( ! V_51 )
return;
}
F_51 ( V_50 , V_50 -> V_53 , V_51 ) ;
}
T_1 F_55 ( struct V_18 * V_19 )
{
const struct V_49 * V_50 = F_53 ( V_19 ) ;
return F_56 ( V_50 -> V_53 >> 1U , 2U ) ;
}
