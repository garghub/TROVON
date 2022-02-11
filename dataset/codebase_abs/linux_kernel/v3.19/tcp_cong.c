static struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 ;
F_2 (e, &tcp_cong_list, list) {
if ( strcmp ( V_3 -> V_2 , V_2 ) == 0 )
return V_3 ;
}
return NULL ;
}
int F_3 ( struct V_1 * V_4 )
{
int V_5 = 0 ;
if ( ! V_4 -> V_6 || ! V_4 -> V_7 ) {
F_4 ( L_1 , V_4 -> V_2 ) ;
return - V_8 ;
}
F_5 ( & V_9 ) ;
if ( F_1 ( V_4 -> V_2 ) ) {
F_6 ( L_2 , V_4 -> V_2 ) ;
V_5 = - V_10 ;
} else {
F_7 ( & V_4 -> V_11 , & V_12 ) ;
F_8 ( L_3 , V_4 -> V_2 ) ;
}
F_9 ( & V_9 ) ;
return V_5 ;
}
void F_10 ( struct V_1 * V_4 )
{
F_5 ( & V_9 ) ;
F_11 ( & V_4 -> V_11 ) ;
F_9 ( & V_9 ) ;
}
void F_12 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_13 ( V_14 ) ;
struct V_1 * V_4 ;
F_14 () ;
F_2 (ca, &tcp_cong_list, list) {
if ( F_15 ( F_16 ( V_4 -> V_17 ) ) ) {
V_16 -> V_18 = V_4 ;
goto V_19;
}
}
V_19:
F_17 () ;
if ( V_4 -> V_20 )
memset ( V_16 -> V_21 , 0 , sizeof( V_16 -> V_21 ) ) ;
}
void F_18 ( struct V_13 * V_14 )
{
const struct V_15 * V_16 = F_13 ( V_14 ) ;
if ( V_16 -> V_18 -> V_22 )
V_16 -> V_18 -> V_22 ( V_14 ) ;
}
void F_19 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_13 ( V_14 ) ;
if ( V_16 -> V_18 -> V_23 )
V_16 -> V_18 -> V_23 ( V_14 ) ;
F_20 ( V_16 -> V_18 -> V_17 ) ;
}
int F_21 ( const char * V_2 )
{
struct V_1 * V_4 ;
int V_5 = - V_24 ;
F_5 ( & V_9 ) ;
V_4 = F_1 ( V_2 ) ;
#ifdef F_22
if ( ! V_4 && F_23 ( V_25 ) ) {
F_9 ( & V_9 ) ;
F_24 ( L_4 , V_2 ) ;
F_5 ( & V_9 ) ;
V_4 = F_1 ( V_2 ) ;
}
#endif
if ( V_4 ) {
V_4 -> V_26 |= V_27 ;
F_25 ( & V_4 -> V_11 , & V_12 ) ;
V_5 = 0 ;
}
F_9 ( & V_9 ) ;
return V_5 ;
}
static int T_1 F_26 ( void )
{
return F_21 ( V_28 ) ;
}
void F_27 ( char * V_29 , T_2 V_30 )
{
struct V_1 * V_4 ;
T_2 V_31 = 0 ;
F_14 () ;
F_2 (ca, &tcp_cong_list, list) {
V_31 += snprintf ( V_29 + V_31 , V_30 - V_31 ,
L_5 ,
V_31 == 0 ? L_6 : L_7 , V_4 -> V_2 ) ;
}
F_17 () ;
}
void F_28 ( char * V_2 )
{
struct V_1 * V_4 ;
F_29 ( F_30 ( & V_12 ) ) ;
F_14 () ;
V_4 = F_31 ( V_12 . V_32 , struct V_1 , V_11 ) ;
strncpy ( V_2 , V_4 -> V_2 , V_33 ) ;
F_17 () ;
}
void F_32 ( char * V_29 , T_2 V_30 )
{
struct V_1 * V_4 ;
T_2 V_31 = 0 ;
* V_29 = '\0' ;
F_14 () ;
F_2 (ca, &tcp_cong_list, list) {
if ( ! ( V_4 -> V_26 & V_27 ) )
continue;
V_31 += snprintf ( V_29 + V_31 , V_30 - V_31 ,
L_5 ,
V_31 == 0 ? L_6 : L_7 , V_4 -> V_2 ) ;
}
F_17 () ;
}
int F_33 ( char * V_34 )
{
struct V_1 * V_4 ;
char * V_35 , * V_36 , * V_2 ;
int V_5 = 0 ;
V_35 = V_36 = F_34 ( V_34 , V_37 ) ;
if ( ! V_36 )
return - V_38 ;
F_5 ( & V_9 ) ;
while ( ( V_2 = F_35 ( & V_36 , L_7 ) ) && * V_2 ) {
V_4 = F_1 ( V_2 ) ;
if ( ! V_4 ) {
V_5 = - V_24 ;
goto V_19;
}
}
F_2 (ca, &tcp_cong_list, list)
V_4 -> V_26 &= ~ V_27 ;
while ( ( V_2 = F_35 ( & V_34 , L_7 ) ) && * V_2 ) {
V_4 = F_1 ( V_2 ) ;
F_36 ( ! V_4 ) ;
if ( V_4 )
V_4 -> V_26 |= V_27 ;
}
V_19:
F_9 ( & V_9 ) ;
F_37 ( V_35 ) ;
return V_5 ;
}
int F_38 ( struct V_13 * V_14 , const char * V_2 )
{
struct V_15 * V_16 = F_13 ( V_14 ) ;
struct V_1 * V_4 ;
int V_39 = 0 ;
F_14 () ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 == V_16 -> V_18 )
goto V_19;
#ifdef F_22
if ( ! V_4 && F_23 ( V_25 ) ) {
F_17 () ;
F_24 ( L_4 , V_2 ) ;
F_14 () ;
V_4 = F_1 ( V_2 ) ;
}
#endif
if ( ! V_4 )
V_39 = - V_24 ;
else if ( ! ( ( V_4 -> V_26 & V_27 ) ||
F_39 ( F_40 ( V_14 ) -> V_40 , V_25 ) ) )
V_39 = - V_41 ;
else if ( ! F_16 ( V_4 -> V_17 ) )
V_39 = - V_42 ;
else {
F_19 ( V_14 ) ;
V_16 -> V_18 = V_4 ;
if ( V_14 -> V_43 != V_44 && V_16 -> V_18 -> V_22 )
V_16 -> V_18 -> V_22 ( V_14 ) ;
}
V_19:
F_17 () ;
return V_39 ;
}
T_3 F_41 ( struct V_45 * V_46 , T_3 V_47 )
{
T_3 V_48 = V_46 -> V_49 + V_47 ;
if ( V_48 > V_46 -> V_50 )
V_48 = V_46 -> V_50 + 1 ;
V_47 -= V_48 - V_46 -> V_49 ;
V_46 -> V_49 = F_42 ( V_48 , V_46 -> V_51 ) ;
return V_47 ;
}
void F_43 ( struct V_45 * V_46 , T_3 V_52 , T_3 V_47 )
{
V_46 -> V_53 += V_47 ;
if ( V_46 -> V_53 >= V_52 ) {
T_3 V_54 = V_46 -> V_53 / V_52 ;
V_46 -> V_53 -= V_54 * V_52 ;
V_46 -> V_49 += V_54 ;
}
V_46 -> V_49 = F_42 ( V_46 -> V_49 , V_46 -> V_51 ) ;
}
void F_44 ( struct V_13 * V_14 , T_3 V_55 , T_3 V_47 )
{
struct V_45 * V_46 = F_45 ( V_14 ) ;
if ( ! F_46 ( V_14 ) )
return;
if ( V_46 -> V_49 <= V_46 -> V_50 ) {
V_47 = F_41 ( V_46 , V_47 ) ;
if ( ! V_47 )
return;
}
F_43 ( V_46 , V_46 -> V_49 , V_47 ) ;
}
T_3 F_47 ( struct V_13 * V_14 )
{
const struct V_45 * V_46 = F_45 ( V_14 ) ;
return F_48 ( V_46 -> V_49 >> 1U , 2U ) ;
}
