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
F_4 ( V_8 L_1 ,
V_4 -> V_2 ) ;
return - V_9 ;
}
F_5 ( & V_10 ) ;
if ( F_1 ( V_4 -> V_2 ) ) {
F_4 ( V_11 L_2 , V_4 -> V_2 ) ;
V_5 = - V_12 ;
} else {
F_6 ( & V_4 -> V_13 , & V_14 ) ;
F_4 ( V_15 L_3 , V_4 -> V_2 ) ;
}
F_7 ( & V_10 ) ;
return V_5 ;
}
void F_8 ( struct V_1 * V_4 )
{
F_5 ( & V_10 ) ;
F_9 ( & V_4 -> V_13 ) ;
F_7 ( & V_10 ) ;
}
void F_10 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_11 ( V_17 ) ;
struct V_1 * V_4 ;
if ( V_19 -> V_20 == & V_21 ) {
F_12 () ;
F_2 (ca, &tcp_cong_list, list) {
if ( F_13 ( V_4 -> V_22 ) ) {
V_19 -> V_20 = V_4 ;
break;
}
}
F_14 () ;
}
if ( V_19 -> V_20 -> V_23 )
V_19 -> V_20 -> V_23 ( V_17 ) ;
}
void F_15 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_11 ( V_17 ) ;
if ( V_19 -> V_20 -> V_24 )
V_19 -> V_20 -> V_24 ( V_17 ) ;
F_16 ( V_19 -> V_20 -> V_22 ) ;
}
int F_17 ( const char * V_2 )
{
struct V_1 * V_4 ;
int V_5 = - V_25 ;
F_5 ( & V_10 ) ;
V_4 = F_1 ( V_2 ) ;
#ifdef F_18
if ( ! V_4 && F_19 ( V_26 ) ) {
F_7 ( & V_10 ) ;
F_20 ( L_4 , V_2 ) ;
F_5 ( & V_10 ) ;
V_4 = F_1 ( V_2 ) ;
}
#endif
if ( V_4 ) {
V_4 -> V_27 |= V_28 ;
F_21 ( & V_4 -> V_13 , & V_14 ) ;
V_5 = 0 ;
}
F_7 ( & V_10 ) ;
return V_5 ;
}
static int T_1 F_22 ( void )
{
return F_17 ( V_29 ) ;
}
void F_23 ( char * V_30 , T_2 V_31 )
{
struct V_1 * V_4 ;
T_2 V_32 = 0 ;
F_12 () ;
F_2 (ca, &tcp_cong_list, list) {
V_32 += snprintf ( V_30 + V_32 , V_31 - V_32 ,
L_5 ,
V_32 == 0 ? L_6 : L_7 , V_4 -> V_2 ) ;
}
F_14 () ;
}
void F_24 ( char * V_2 )
{
struct V_1 * V_4 ;
F_25 ( F_26 ( & V_14 ) ) ;
F_12 () ;
V_4 = F_27 ( V_14 . V_33 , struct V_1 , V_13 ) ;
strncpy ( V_2 , V_4 -> V_2 , V_34 ) ;
F_14 () ;
}
void F_28 ( char * V_30 , T_2 V_31 )
{
struct V_1 * V_4 ;
T_2 V_32 = 0 ;
* V_30 = '\0' ;
F_12 () ;
F_2 (ca, &tcp_cong_list, list) {
if ( ! ( V_4 -> V_27 & V_28 ) )
continue;
V_32 += snprintf ( V_30 + V_32 , V_31 - V_32 ,
L_5 ,
V_32 == 0 ? L_6 : L_7 , V_4 -> V_2 ) ;
}
F_14 () ;
}
int F_29 ( char * V_35 )
{
struct V_1 * V_4 ;
char * V_36 , * V_37 , * V_2 ;
int V_5 = 0 ;
V_36 = V_37 = F_30 ( V_35 , V_38 ) ;
if ( ! V_37 )
return - V_39 ;
F_5 ( & V_10 ) ;
while ( ( V_2 = F_31 ( & V_37 , L_7 ) ) && * V_2 ) {
V_4 = F_1 ( V_2 ) ;
if ( ! V_4 ) {
V_5 = - V_25 ;
goto V_40;
}
}
F_2 (ca, &tcp_cong_list, list)
V_4 -> V_27 &= ~ V_28 ;
while ( ( V_2 = F_31 ( & V_35 , L_7 ) ) && * V_2 ) {
V_4 = F_1 ( V_2 ) ;
F_32 ( ! V_4 ) ;
if ( V_4 )
V_4 -> V_27 |= V_28 ;
}
V_40:
F_7 ( & V_10 ) ;
F_33 ( V_36 ) ;
return V_5 ;
}
int F_34 ( struct V_16 * V_17 , const char * V_2 )
{
struct V_18 * V_19 = F_11 ( V_17 ) ;
struct V_1 * V_4 ;
int V_41 = 0 ;
F_12 () ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 == V_19 -> V_20 )
goto V_40;
#ifdef F_18
if ( ! V_4 && F_19 ( V_26 ) ) {
F_14 () ;
F_20 ( L_4 , V_2 ) ;
F_12 () ;
V_4 = F_1 ( V_2 ) ;
}
#endif
if ( ! V_4 )
V_41 = - V_25 ;
else if ( ! ( ( V_4 -> V_27 & V_28 ) || F_19 ( V_26 ) ) )
V_41 = - V_42 ;
else if ( ! F_13 ( V_4 -> V_22 ) )
V_41 = - V_43 ;
else {
F_15 ( V_17 ) ;
V_19 -> V_20 = V_4 ;
if ( V_17 -> V_44 != V_45 && V_19 -> V_20 -> V_23 )
V_19 -> V_20 -> V_23 ( V_17 ) ;
}
V_40:
F_14 () ;
return V_41 ;
}
int F_35 ( const struct V_16 * V_17 , T_3 V_46 )
{
const struct V_47 * V_48 = F_36 ( V_17 ) ;
T_3 V_49 ;
if ( V_46 >= V_48 -> V_50 )
return 1 ;
V_49 = V_48 -> V_50 - V_46 ;
if ( F_37 ( V_17 ) &&
V_49 * V_51 < V_48 -> V_50 &&
V_49 * V_48 -> V_52 < V_17 -> V_53 )
return 1 ;
return V_49 <= F_38 ( V_48 ) ;
}
void F_39 ( struct V_47 * V_48 )
{
int V_54 ;
if ( V_55 && V_48 -> V_56 < V_48 -> V_52 )
return;
if ( V_57 > 0 && V_48 -> V_50 > V_57 )
V_54 = V_57 >> 1 ;
else
V_54 = V_48 -> V_50 ;
if ( V_55 > 1 && V_48 -> V_56 >= 2 * V_48 -> V_52 )
V_54 <<= 1 ;
V_48 -> V_56 = 0 ;
V_48 -> V_58 += V_54 ;
while ( V_48 -> V_58 >= V_48 -> V_50 ) {
V_48 -> V_58 -= V_48 -> V_50 ;
if ( V_48 -> V_50 < V_48 -> V_59 )
V_48 -> V_50 ++ ;
}
}
void F_40 ( struct V_47 * V_48 , T_3 V_60 )
{
if ( V_48 -> V_58 >= V_60 ) {
if ( V_48 -> V_50 < V_48 -> V_59 )
V_48 -> V_50 ++ ;
V_48 -> V_58 = 0 ;
} else {
V_48 -> V_58 ++ ;
}
}
void F_41 ( struct V_16 * V_17 , T_3 V_61 , T_3 V_46 )
{
struct V_47 * V_48 = F_36 ( V_17 ) ;
if ( ! F_35 ( V_17 , V_46 ) )
return;
if ( V_48 -> V_50 <= V_48 -> V_62 )
F_39 ( V_48 ) ;
else if ( V_55 ) {
if ( V_48 -> V_56 >= V_48 -> V_50 * V_48 -> V_52 ) {
V_48 -> V_56 -= V_48 -> V_50 * V_48 -> V_52 ;
if ( V_48 -> V_50 < V_48 -> V_59 )
V_48 -> V_50 ++ ;
}
} else {
F_40 ( V_48 , V_48 -> V_50 ) ;
}
}
T_3 F_42 ( struct V_16 * V_17 )
{
const struct V_47 * V_48 = F_36 ( V_17 ) ;
return F_43 ( V_48 -> V_50 >> 1U , 2U ) ;
}
T_3 F_44 ( const struct V_16 * V_17 )
{
const struct V_47 * V_48 = F_36 ( V_17 ) ;
return V_48 -> V_62 / 2 ;
}
