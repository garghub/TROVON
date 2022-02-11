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
if ( ! V_4 -> V_8 || ! V_4 -> V_9 ||
! ( V_4 -> V_10 || V_4 -> V_11 ) ) {
F_11 ( L_2 , V_4 -> V_2 ) ;
return - V_12 ;
}
V_4 -> V_6 = F_12 ( V_4 -> V_2 , sizeof( V_4 -> V_2 ) , strlen ( V_4 -> V_2 ) ) ;
F_13 ( & V_13 ) ;
if ( V_4 -> V_6 == V_14 || F_9 ( V_4 -> V_6 ) ) {
F_14 ( L_3 ,
V_4 -> V_2 ) ;
V_7 = - V_15 ;
} else {
F_15 ( & V_4 -> V_16 , & V_17 ) ;
F_16 ( L_4 , V_4 -> V_2 ) ;
}
F_17 ( & V_13 ) ;
return V_7 ;
}
void F_18 ( struct V_1 * V_4 )
{
F_13 ( & V_13 ) ;
F_19 ( & V_4 -> V_16 ) ;
F_17 ( & V_13 ) ;
F_20 () ;
}
T_1 F_21 ( const char * V_2 , bool * V_18 )
{
const struct V_1 * V_4 ;
T_1 V_6 = V_14 ;
F_22 () ;
F_8 () ;
V_4 = F_3 ( V_2 ) ;
if ( V_4 ) {
V_6 = V_4 -> V_6 ;
* V_18 = V_4 -> V_19 & V_20 ;
}
F_6 () ;
return V_6 ;
}
char * F_23 ( T_1 V_6 , char * V_21 )
{
const struct V_1 * V_4 ;
char * V_7 = NULL ;
F_8 () ;
V_4 = F_9 ( V_6 ) ;
if ( V_4 )
V_7 = strncpy ( V_21 , V_4 -> V_2 ,
V_22 ) ;
F_6 () ;
return V_7 ;
}
void F_24 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_25 ( V_24 ) ;
struct V_1 * V_4 ;
F_8 () ;
F_2 (ca, &tcp_cong_list, list) {
if ( F_26 ( F_27 ( V_4 -> V_27 ) ) ) {
V_26 -> V_28 = V_4 ;
goto V_29;
}
}
V_29:
F_6 () ;
memset ( V_26 -> V_30 , 0 , sizeof( V_26 -> V_30 ) ) ;
if ( V_4 -> V_19 & V_20 )
F_28 ( V_24 ) ;
else
F_29 ( V_24 ) ;
}
void F_30 ( struct V_23 * V_24 )
{
const struct V_25 * V_26 = F_25 ( V_24 ) ;
if ( V_26 -> V_28 -> V_31 )
V_26 -> V_28 -> V_31 ( V_24 ) ;
if ( F_31 ( V_24 ) )
F_28 ( V_24 ) ;
else
F_29 ( V_24 ) ;
}
static void F_32 ( struct V_23 * V_24 ,
const struct V_1 * V_4 )
{
struct V_25 * V_26 = F_25 ( V_24 ) ;
F_33 ( V_24 ) ;
V_26 -> V_28 = V_4 ;
V_26 -> V_32 = 1 ;
memset ( V_26 -> V_30 , 0 , sizeof( V_26 -> V_30 ) ) ;
if ( V_24 -> V_33 != V_34 )
F_30 ( V_24 ) ;
}
void F_33 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_25 ( V_24 ) ;
if ( V_26 -> V_28 -> V_35 )
V_26 -> V_28 -> V_35 ( V_24 ) ;
F_34 ( V_26 -> V_28 -> V_27 ) ;
}
int F_35 ( const char * V_2 )
{
struct V_1 * V_4 ;
int V_7 = - V_36 ;
F_13 ( & V_13 ) ;
V_4 = F_1 ( V_2 ) ;
#ifdef F_4
if ( ! V_4 && F_5 ( V_5 ) ) {
F_17 ( & V_13 ) ;
F_7 ( L_1 , V_2 ) ;
F_13 ( & V_13 ) ;
V_4 = F_1 ( V_2 ) ;
}
#endif
if ( V_4 ) {
V_4 -> V_19 |= V_37 ;
F_36 ( & V_4 -> V_16 , & V_17 ) ;
V_7 = 0 ;
}
F_17 ( & V_13 ) ;
return V_7 ;
}
static int T_2 F_37 ( void )
{
return F_35 ( V_38 ) ;
}
void F_38 ( char * V_39 , T_3 V_40 )
{
struct V_1 * V_4 ;
T_3 V_41 = 0 ;
F_8 () ;
F_2 (ca, &tcp_cong_list, list) {
V_41 += snprintf ( V_39 + V_41 , V_40 - V_41 ,
L_5 ,
V_41 == 0 ? L_6 : L_7 , V_4 -> V_2 ) ;
}
F_6 () ;
}
void F_39 ( char * V_2 )
{
struct V_1 * V_4 ;
F_40 ( F_41 ( & V_17 ) ) ;
F_8 () ;
V_4 = F_42 ( V_17 . V_42 , struct V_1 , V_16 ) ;
strncpy ( V_2 , V_4 -> V_2 , V_22 ) ;
F_6 () ;
}
void F_43 ( char * V_39 , T_3 V_40 )
{
struct V_1 * V_4 ;
T_3 V_41 = 0 ;
* V_39 = '\0' ;
F_8 () ;
F_2 (ca, &tcp_cong_list, list) {
if ( ! ( V_4 -> V_19 & V_37 ) )
continue;
V_41 += snprintf ( V_39 + V_41 , V_40 - V_41 ,
L_5 ,
V_41 == 0 ? L_6 : L_7 , V_4 -> V_2 ) ;
}
F_6 () ;
}
int F_44 ( char * V_43 )
{
struct V_1 * V_4 ;
char * V_44 , * V_45 , * V_2 ;
int V_7 = 0 ;
V_44 = V_45 = F_45 ( V_43 , V_46 ) ;
if ( ! V_45 )
return - V_47 ;
F_13 ( & V_13 ) ;
while ( ( V_2 = F_46 ( & V_45 , L_7 ) ) && * V_2 ) {
V_4 = F_1 ( V_2 ) ;
if ( ! V_4 ) {
V_7 = - V_36 ;
goto V_29;
}
}
F_2 (ca, &tcp_cong_list, list)
V_4 -> V_19 &= ~ V_37 ;
while ( ( V_2 = F_46 ( & V_43 , L_7 ) ) && * V_2 ) {
V_4 = F_1 ( V_2 ) ;
F_47 ( ! V_4 ) ;
if ( V_4 )
V_4 -> V_19 |= V_37 ;
}
V_29:
F_17 ( & V_13 ) ;
F_48 ( V_44 ) ;
return V_7 ;
}
int F_49 ( struct V_23 * V_24 , const char * V_2 )
{
struct V_25 * V_26 = F_25 ( V_24 ) ;
const struct V_1 * V_4 ;
int V_48 = 0 ;
if ( V_26 -> V_49 )
return - V_50 ;
F_8 () ;
V_4 = F_3 ( V_2 ) ;
if ( V_4 == V_26 -> V_28 ) {
V_26 -> V_32 = 1 ;
goto V_29;
}
if ( ! V_4 )
V_48 = - V_36 ;
else if ( ! ( ( V_4 -> V_19 & V_37 ) ||
F_50 ( F_51 ( V_24 ) -> V_51 , V_5 ) ) )
V_48 = - V_50 ;
else if ( ! F_27 ( V_4 -> V_27 ) )
V_48 = - V_52 ;
else
F_32 ( V_24 , V_4 ) ;
V_29:
F_6 () ;
return V_48 ;
}
T_1 F_52 ( struct V_53 * V_54 , T_1 V_55 )
{
T_1 V_56 = F_53 ( V_54 -> V_57 + V_55 , V_54 -> V_58 ) ;
V_55 -= V_56 - V_54 -> V_57 ;
V_54 -> V_57 = F_53 ( V_56 , V_54 -> V_59 ) ;
return V_55 ;
}
void F_54 ( struct V_53 * V_54 , T_1 V_60 , T_1 V_55 )
{
if ( V_54 -> V_61 >= V_60 ) {
V_54 -> V_61 = 0 ;
V_54 -> V_57 ++ ;
}
V_54 -> V_61 += V_55 ;
if ( V_54 -> V_61 >= V_60 ) {
T_1 V_62 = V_54 -> V_61 / V_60 ;
V_54 -> V_61 -= V_62 * V_60 ;
V_54 -> V_57 += V_62 ;
}
V_54 -> V_57 = F_53 ( V_54 -> V_57 , V_54 -> V_59 ) ;
}
void F_55 ( struct V_23 * V_24 , T_1 V_63 , T_1 V_55 )
{
struct V_53 * V_54 = F_56 ( V_24 ) ;
if ( ! F_57 ( V_24 ) )
return;
if ( F_58 ( V_54 ) ) {
V_55 = F_52 ( V_54 , V_55 ) ;
if ( ! V_55 )
return;
}
F_54 ( V_54 , V_54 -> V_57 , V_55 ) ;
}
T_1 F_59 ( struct V_23 * V_24 )
{
const struct V_53 * V_54 = F_56 ( V_24 ) ;
return F_60 ( V_54 -> V_57 >> 1U , 2U ) ;
}
T_1 F_61 ( struct V_23 * V_24 )
{
const struct V_53 * V_54 = F_56 ( V_24 ) ;
return F_60 ( V_54 -> V_57 , V_54 -> V_58 << 1 ) ;
}
