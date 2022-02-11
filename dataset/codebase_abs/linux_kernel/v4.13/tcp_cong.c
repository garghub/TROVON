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
F_31 ( V_24 ) -> V_31 = 0 ;
if ( V_26 -> V_28 -> V_32 )
V_26 -> V_28 -> V_32 ( V_24 ) ;
if ( F_32 ( V_24 ) )
F_28 ( V_24 ) ;
else
F_29 ( V_24 ) ;
}
static void F_33 ( struct V_23 * V_24 ,
const struct V_1 * V_4 )
{
struct V_25 * V_26 = F_25 ( V_24 ) ;
F_34 ( V_24 ) ;
V_26 -> V_28 = V_4 ;
V_26 -> V_33 = 1 ;
memset ( V_26 -> V_30 , 0 , sizeof( V_26 -> V_30 ) ) ;
if ( V_24 -> V_34 != V_35 )
F_30 ( V_24 ) ;
}
void F_34 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_25 ( V_24 ) ;
if ( V_26 -> V_28 -> V_36 )
V_26 -> V_28 -> V_36 ( V_24 ) ;
F_35 ( V_26 -> V_28 -> V_27 ) ;
}
int F_36 ( const char * V_2 )
{
struct V_1 * V_4 ;
int V_7 = - V_37 ;
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
V_4 -> V_19 |= V_38 ;
F_37 ( & V_4 -> V_16 , & V_17 ) ;
V_7 = 0 ;
}
F_17 ( & V_13 ) ;
return V_7 ;
}
static int T_2 F_38 ( void )
{
return F_36 ( V_39 ) ;
}
void F_39 ( char * V_40 , T_3 V_41 )
{
struct V_1 * V_4 ;
T_3 V_42 = 0 ;
F_8 () ;
F_2 (ca, &tcp_cong_list, list) {
V_42 += snprintf ( V_40 + V_42 , V_41 - V_42 ,
L_5 ,
V_42 == 0 ? L_6 : L_7 , V_4 -> V_2 ) ;
}
F_6 () ;
}
void F_40 ( char * V_2 )
{
struct V_1 * V_4 ;
F_41 ( F_42 ( & V_17 ) ) ;
F_8 () ;
V_4 = F_43 ( V_17 . V_43 , struct V_1 , V_16 ) ;
strncpy ( V_2 , V_4 -> V_2 , V_22 ) ;
F_6 () ;
}
void F_44 ( char * V_40 , T_3 V_41 )
{
struct V_1 * V_4 ;
T_3 V_42 = 0 ;
* V_40 = '\0' ;
F_8 () ;
F_2 (ca, &tcp_cong_list, list) {
if ( ! ( V_4 -> V_19 & V_38 ) )
continue;
V_42 += snprintf ( V_40 + V_42 , V_41 - V_42 ,
L_5 ,
V_42 == 0 ? L_6 : L_7 , V_4 -> V_2 ) ;
}
F_6 () ;
}
int F_45 ( char * V_44 )
{
struct V_1 * V_4 ;
char * V_45 , * V_46 , * V_2 ;
int V_7 = 0 ;
V_45 = V_46 = F_46 ( V_44 , V_47 ) ;
if ( ! V_46 )
return - V_48 ;
F_13 ( & V_13 ) ;
while ( ( V_2 = F_47 ( & V_46 , L_7 ) ) && * V_2 ) {
V_4 = F_1 ( V_2 ) ;
if ( ! V_4 ) {
V_7 = - V_37 ;
goto V_29;
}
}
F_2 (ca, &tcp_cong_list, list)
V_4 -> V_19 &= ~ V_38 ;
while ( ( V_2 = F_47 ( & V_44 , L_7 ) ) && * V_2 ) {
V_4 = F_1 ( V_2 ) ;
F_48 ( ! V_4 ) ;
if ( V_4 )
V_4 -> V_19 |= V_38 ;
}
V_29:
F_17 ( & V_13 ) ;
F_49 ( V_45 ) ;
return V_7 ;
}
int F_50 ( struct V_23 * V_24 , const char * V_2 , bool V_49 , bool V_50 )
{
struct V_25 * V_26 = F_25 ( V_24 ) ;
const struct V_1 * V_4 ;
int V_51 = 0 ;
if ( V_26 -> V_52 )
return - V_53 ;
F_8 () ;
if ( ! V_49 )
V_4 = F_1 ( V_2 ) ;
else
V_4 = F_3 ( V_2 ) ;
if ( V_4 == V_26 -> V_28 ) {
V_26 -> V_33 = 1 ;
goto V_29;
}
if ( ! V_4 ) {
V_51 = - V_37 ;
} else if ( ! V_49 ) {
const struct V_1 * V_54 = V_26 -> V_28 ;
if ( F_27 ( V_4 -> V_27 ) ) {
if ( V_50 ) {
F_33 ( V_24 , V_4 ) ;
} else {
V_26 -> V_28 = V_4 ;
F_35 ( V_54 -> V_27 ) ;
}
} else {
V_51 = - V_55 ;
}
} else if ( ! ( ( V_4 -> V_19 & V_38 ) ||
F_51 ( F_52 ( V_24 ) -> V_56 , V_5 ) ) ) {
V_51 = - V_53 ;
} else if ( ! F_27 ( V_4 -> V_27 ) ) {
V_51 = - V_55 ;
} else {
F_33 ( V_24 , V_4 ) ;
}
V_29:
F_6 () ;
return V_51 ;
}
T_1 F_53 ( struct V_57 * V_58 , T_1 V_59 )
{
T_1 V_60 = F_54 ( V_58 -> V_61 + V_59 , V_58 -> V_62 ) ;
V_59 -= V_60 - V_58 -> V_61 ;
V_58 -> V_61 = F_54 ( V_60 , V_58 -> V_63 ) ;
return V_59 ;
}
void F_55 ( struct V_57 * V_58 , T_1 V_64 , T_1 V_59 )
{
if ( V_58 -> V_65 >= V_64 ) {
V_58 -> V_65 = 0 ;
V_58 -> V_61 ++ ;
}
V_58 -> V_65 += V_59 ;
if ( V_58 -> V_65 >= V_64 ) {
T_1 V_66 = V_58 -> V_65 / V_64 ;
V_58 -> V_65 -= V_66 * V_64 ;
V_58 -> V_61 += V_66 ;
}
V_58 -> V_61 = F_54 ( V_58 -> V_61 , V_58 -> V_63 ) ;
}
void F_56 ( struct V_23 * V_24 , T_1 V_67 , T_1 V_59 )
{
struct V_57 * V_58 = F_31 ( V_24 ) ;
if ( ! F_57 ( V_24 ) )
return;
if ( F_58 ( V_58 ) ) {
V_59 = F_53 ( V_58 , V_59 ) ;
if ( ! V_59 )
return;
}
F_55 ( V_58 , V_58 -> V_61 , V_59 ) ;
}
T_1 F_59 ( struct V_23 * V_24 )
{
const struct V_57 * V_58 = F_31 ( V_24 ) ;
return F_60 ( V_58 -> V_61 >> 1U , 2U ) ;
}
T_1 F_61 ( struct V_23 * V_24 )
{
const struct V_57 * V_58 = F_31 ( V_24 ) ;
return F_60 ( V_58 -> V_61 , V_58 -> V_62 << 1 ) ;
}
