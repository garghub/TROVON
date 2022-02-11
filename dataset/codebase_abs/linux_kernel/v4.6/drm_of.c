static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_5 = 0 ;
struct V_6 * V_7 ;
F_2 (tmp, dev) {
if ( V_7 -> V_4 == V_4 )
return 1 << V_5 ;
V_5 ++ ;
}
return 0 ;
}
T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_8 , * V_9 ;
T_1 V_10 = 0 ;
F_4 (port, ep) {
V_8 = F_5 ( V_9 ) ;
if ( ! V_8 ) {
F_6 ( V_9 ) ;
return 0 ;
}
V_10 |= F_1 ( V_2 , V_8 ) ;
F_6 ( V_8 ) ;
}
return V_10 ;
}
int F_7 ( struct V_11 * V_2 ,
int (* F_8)( struct V_11 * , void * ) ,
const struct V_12 * V_13 )
{
struct V_3 * V_9 , * V_4 , * V_14 ;
struct V_15 * V_16 = NULL ;
int V_17 ;
if ( ! V_2 -> V_18 )
return - V_19 ;
for ( V_17 = 0 ; ; V_17 ++ ) {
V_4 = F_9 ( V_2 -> V_18 , L_1 , V_17 ) ;
if ( ! V_4 )
break;
if ( ! F_10 ( V_4 -> V_20 ) ) {
F_6 ( V_4 ) ;
continue;
}
F_11 ( V_2 , & V_16 , F_8 , V_4 ) ;
F_6 ( V_4 ) ;
}
if ( V_17 == 0 ) {
F_12 ( V_2 , L_2 ) ;
return - V_21 ;
}
if ( ! V_16 ) {
F_12 ( V_2 , L_3 ) ;
return - V_21 ;
}
for ( V_17 = 0 ; ; V_17 ++ ) {
V_4 = F_9 ( V_2 -> V_18 , L_1 , V_17 ) ;
if ( ! V_4 )
break;
if ( ! F_10 ( V_4 -> V_20 ) ) {
F_6 ( V_4 ) ;
continue;
}
F_13 (port, ep) {
V_14 = F_14 ( V_9 ) ;
if ( ! V_14 || ! F_10 ( V_14 ) ) {
F_6 ( V_14 ) ;
continue;
} else if ( ! F_10 ( V_14 -> V_20 ) ) {
F_15 ( V_2 , L_4 ,
V_14 -> V_22 ) ;
F_6 ( V_14 ) ;
continue;
}
F_11 ( V_2 , & V_16 , F_8 , V_14 ) ;
F_6 ( V_14 ) ;
}
F_6 ( V_4 ) ;
}
return F_16 ( V_2 , V_13 , V_16 ) ;
}
int F_17 ( struct V_3 * V_23 ,
struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_3 * V_9 ;
struct V_6 * V_28 = V_25 -> V_28 ;
struct V_3 * V_4 ;
int V_29 ;
if ( ! V_23 || ! V_28 )
return - V_19 ;
F_4 (node, ep) {
V_4 = F_5 ( V_9 ) ;
F_6 ( V_4 ) ;
if ( V_4 == V_28 -> V_4 ) {
V_29 = F_18 ( V_9 , V_27 ) ;
F_6 ( V_9 ) ;
return V_29 ;
}
}
return - V_19 ;
}
