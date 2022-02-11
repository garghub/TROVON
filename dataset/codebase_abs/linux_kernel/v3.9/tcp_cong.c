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
if ( V_16 -> V_17 == & V_18 ) {
F_14 () ;
F_2 (ca, &tcp_cong_list, list) {
if ( F_15 ( V_4 -> V_19 ) ) {
V_16 -> V_17 = V_4 ;
break;
}
}
F_16 () ;
}
if ( V_16 -> V_17 -> V_20 )
V_16 -> V_17 -> V_20 ( V_14 ) ;
}
void F_17 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_13 ( V_14 ) ;
if ( V_16 -> V_17 -> V_21 )
V_16 -> V_17 -> V_21 ( V_14 ) ;
F_18 ( V_16 -> V_17 -> V_19 ) ;
}
int F_19 ( const char * V_2 )
{
struct V_1 * V_4 ;
int V_5 = - V_22 ;
F_5 ( & V_9 ) ;
V_4 = F_1 ( V_2 ) ;
#ifdef F_20
if ( ! V_4 && F_21 ( V_23 ) ) {
F_9 ( & V_9 ) ;
F_22 ( L_4 , V_2 ) ;
F_5 ( & V_9 ) ;
V_4 = F_1 ( V_2 ) ;
}
#endif
if ( V_4 ) {
V_4 -> V_24 |= V_25 ;
F_23 ( & V_4 -> V_11 , & V_12 ) ;
V_5 = 0 ;
}
F_9 ( & V_9 ) ;
return V_5 ;
}
static int T_1 F_24 ( void )
{
return F_19 ( V_26 ) ;
}
void F_25 ( char * V_27 , T_2 V_28 )
{
struct V_1 * V_4 ;
T_2 V_29 = 0 ;
F_14 () ;
F_2 (ca, &tcp_cong_list, list) {
V_29 += snprintf ( V_27 + V_29 , V_28 - V_29 ,
L_5 ,
V_29 == 0 ? L_6 : L_7 , V_4 -> V_2 ) ;
}
F_16 () ;
}
void F_26 ( char * V_2 )
{
struct V_1 * V_4 ;
F_27 ( F_28 ( & V_12 ) ) ;
F_14 () ;
V_4 = F_29 ( V_12 . V_30 , struct V_1 , V_11 ) ;
strncpy ( V_2 , V_4 -> V_2 , V_31 ) ;
F_16 () ;
}
void F_30 ( char * V_27 , T_2 V_28 )
{
struct V_1 * V_4 ;
T_2 V_29 = 0 ;
* V_27 = '\0' ;
F_14 () ;
F_2 (ca, &tcp_cong_list, list) {
if ( ! ( V_4 -> V_24 & V_25 ) )
continue;
V_29 += snprintf ( V_27 + V_29 , V_28 - V_29 ,
L_5 ,
V_29 == 0 ? L_6 : L_7 , V_4 -> V_2 ) ;
}
F_16 () ;
}
int F_31 ( char * V_32 )
{
struct V_1 * V_4 ;
char * V_33 , * V_34 , * V_2 ;
int V_5 = 0 ;
V_33 = V_34 = F_32 ( V_32 , V_35 ) ;
if ( ! V_34 )
return - V_36 ;
F_5 ( & V_9 ) ;
while ( ( V_2 = F_33 ( & V_34 , L_7 ) ) && * V_2 ) {
V_4 = F_1 ( V_2 ) ;
if ( ! V_4 ) {
V_5 = - V_22 ;
goto V_37;
}
}
F_2 (ca, &tcp_cong_list, list)
V_4 -> V_24 &= ~ V_25 ;
while ( ( V_2 = F_33 ( & V_32 , L_7 ) ) && * V_2 ) {
V_4 = F_1 ( V_2 ) ;
F_34 ( ! V_4 ) ;
if ( V_4 )
V_4 -> V_24 |= V_25 ;
}
V_37:
F_9 ( & V_9 ) ;
F_35 ( V_33 ) ;
return V_5 ;
}
int F_36 ( struct V_13 * V_14 , const char * V_2 )
{
struct V_15 * V_16 = F_13 ( V_14 ) ;
struct V_1 * V_4 ;
int V_38 = 0 ;
F_14 () ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 == V_16 -> V_17 )
goto V_37;
#ifdef F_20
if ( ! V_4 && F_21 ( V_23 ) ) {
F_16 () ;
F_22 ( L_4 , V_2 ) ;
F_14 () ;
V_4 = F_1 ( V_2 ) ;
}
#endif
if ( ! V_4 )
V_38 = - V_22 ;
else if ( ! ( ( V_4 -> V_24 & V_25 ) ||
F_37 ( F_38 ( V_14 ) -> V_39 , V_23 ) ) )
V_38 = - V_40 ;
else if ( ! F_15 ( V_4 -> V_19 ) )
V_38 = - V_41 ;
else {
F_17 ( V_14 ) ;
V_16 -> V_17 = V_4 ;
if ( V_14 -> V_42 != V_43 && V_16 -> V_17 -> V_20 )
V_16 -> V_17 -> V_20 ( V_14 ) ;
}
V_37:
F_16 () ;
return V_38 ;
}
bool F_39 ( const struct V_13 * V_14 , T_3 V_44 )
{
const struct V_45 * V_46 = F_40 ( V_14 ) ;
T_3 V_47 ;
if ( V_44 >= V_46 -> V_48 )
return true ;
V_47 = V_46 -> V_48 - V_44 ;
if ( F_41 ( V_14 ) &&
V_47 * V_49 < V_46 -> V_48 &&
V_47 * V_46 -> V_50 < V_14 -> V_51 &&
V_47 < V_14 -> V_52 )
return true ;
return V_47 <= F_42 ( V_46 ) ;
}
void F_43 ( struct V_45 * V_46 )
{
int V_53 ;
unsigned int V_54 = 0 ;
T_3 V_48 = V_46 -> V_48 ;
if ( F_44 ( ! V_48 ) ) {
F_45 ( L_8 ) ;
V_48 = 1U ;
}
if ( V_55 > 0 && V_46 -> V_48 > V_55 )
V_53 = V_55 >> 1 ;
else
V_53 = V_48 ;
V_46 -> V_56 += V_53 ;
while ( V_46 -> V_56 >= V_48 ) {
V_46 -> V_56 -= V_48 ;
V_54 ++ ;
}
V_46 -> V_48 = F_46 ( V_48 + V_54 , V_46 -> V_57 ) ;
}
void F_47 ( struct V_45 * V_46 , T_3 V_58 )
{
if ( V_46 -> V_56 >= V_58 ) {
if ( V_46 -> V_48 < V_46 -> V_57 )
V_46 -> V_48 ++ ;
V_46 -> V_56 = 0 ;
} else {
V_46 -> V_56 ++ ;
}
}
void F_48 ( struct V_13 * V_14 , T_3 V_59 , T_3 V_44 )
{
struct V_45 * V_46 = F_40 ( V_14 ) ;
if ( ! F_39 ( V_14 , V_44 ) )
return;
if ( V_46 -> V_48 <= V_46 -> V_60 )
F_43 ( V_46 ) ;
else
F_47 ( V_46 , V_46 -> V_48 ) ;
}
T_3 F_49 ( struct V_13 * V_14 )
{
const struct V_45 * V_46 = F_40 ( V_14 ) ;
return F_50 ( V_46 -> V_48 >> 1U , 2U ) ;
}
T_3 F_51 ( const struct V_13 * V_14 )
{
const struct V_45 * V_46 = F_40 ( V_14 ) ;
return V_46 -> V_60 / 2 ;
}
