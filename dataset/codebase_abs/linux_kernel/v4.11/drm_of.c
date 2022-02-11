static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( V_3 ) ;
}
static T_1 F_3 ( struct V_4 * V_2 ,
struct V_5 * V_6 )
{
unsigned int V_7 = 0 ;
struct V_8 * V_9 ;
F_4 (tmp, dev) {
if ( V_9 -> V_6 == V_6 )
return 1 << V_7 ;
V_7 ++ ;
}
return 0 ;
}
T_1 F_5 ( struct V_4 * V_2 ,
struct V_5 * V_6 )
{
struct V_5 * V_10 , * V_11 ;
T_1 V_12 = 0 ;
F_6 (port, ep) {
V_10 = F_7 ( V_11 ) ;
if ( ! V_10 ) {
F_2 ( V_11 ) ;
return 0 ;
}
V_12 |= F_3 ( V_2 , V_10 ) ;
F_2 ( V_10 ) ;
}
return V_12 ;
}
void F_8 ( struct V_1 * V_13 ,
struct V_14 * * V_15 ,
int (* F_9)( struct V_1 * , void * ) ,
struct V_5 * V_16 )
{
F_10 ( V_16 ) ;
F_11 ( V_13 , V_15 , F_1 ,
F_9 , V_16 ) ;
}
int F_12 ( struct V_1 * V_2 ,
int (* F_13)( struct V_1 * , void * ) ,
const struct V_17 * V_18 )
{
struct V_5 * V_11 , * V_6 , * V_19 ;
struct V_14 * V_20 = NULL ;
int V_21 ;
if ( ! V_2 -> V_22 )
return - V_23 ;
for ( V_21 = 0 ; ; V_21 ++ ) {
V_6 = F_14 ( V_2 -> V_22 , L_1 , V_21 ) ;
if ( ! V_6 )
break;
if ( ! F_15 ( V_6 -> V_24 ) ) {
F_2 ( V_6 ) ;
continue;
}
F_8 ( V_2 , & V_20 , F_13 , V_6 ) ;
F_2 ( V_6 ) ;
}
if ( V_21 == 0 ) {
F_16 ( V_2 , L_2 ) ;
return - V_25 ;
}
if ( ! V_20 ) {
F_16 ( V_2 , L_3 ) ;
return - V_25 ;
}
for ( V_21 = 0 ; ; V_21 ++ ) {
V_6 = F_14 ( V_2 -> V_22 , L_1 , V_21 ) ;
if ( ! V_6 )
break;
if ( ! F_15 ( V_6 -> V_24 ) ) {
F_2 ( V_6 ) ;
continue;
}
F_17 (port, ep) {
V_19 = F_18 ( V_11 ) ;
if ( ! V_19 || ! F_15 ( V_19 ) ) {
F_2 ( V_19 ) ;
continue;
} else if ( ! F_15 ( V_19 -> V_24 ) ) {
F_19 ( V_2 , L_4 ,
V_19 -> V_26 ) ;
F_2 ( V_19 ) ;
continue;
}
F_8 ( V_2 , & V_20 , F_13 ,
V_19 ) ;
F_2 ( V_19 ) ;
}
F_2 ( V_6 ) ;
}
return F_20 ( V_2 , V_18 , V_20 ) ;
}
int F_21 ( struct V_5 * V_16 ,
struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_5 * V_11 ;
struct V_8 * V_31 = V_28 -> V_31 ;
struct V_5 * V_6 ;
int V_32 ;
if ( ! V_16 || ! V_31 )
return - V_23 ;
F_6 (node, ep) {
V_6 = F_7 ( V_11 ) ;
F_2 ( V_6 ) ;
if ( V_6 == V_31 -> V_6 ) {
V_32 = F_22 ( V_11 , V_30 ) ;
F_2 ( V_11 ) ;
return V_32 ;
}
}
return - V_23 ;
}
