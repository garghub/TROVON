int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 ;
struct V_3 * V_10 = NULL ;
struct V_11 * V_12 ;
struct V_13 * V_14 , * V_15 ;
struct V_5 * V_16 ;
short V_17 = 0 ;
int V_18 = 0 ;
if ( ( V_9 = F_2 ( V_2 ) ) == NULL )
goto V_19;
if ( ( V_10 = F_3 ( V_9 -> V_20 ) ) == NULL ) {
goto V_21;
}
if ( V_9 -> V_20 == V_4 -> V_20 ) {
goto V_22;
}
F_4 ( & V_23 ) ;
F_5 (entry, &x25_forward_list) {
V_14 = F_6 ( V_12 , struct V_13 , V_24 ) ;
if ( V_14 -> V_7 == V_7 ) {
F_7 ( V_25 L_1 ) ;
V_17 = 1 ;
}
}
F_8 ( & V_23 ) ;
if ( ! V_17 ) {
if ( ( V_15 = F_9 ( sizeof( struct V_13 ) ,
V_26 ) ) == NULL ) {
V_18 = - V_27 ;
goto V_22;
}
V_15 -> V_7 = V_7 ;
V_15 -> V_28 = V_9 -> V_20 ;
V_15 -> V_29 = V_4 -> V_20 ;
F_10 ( & V_23 ) ;
F_11 ( & V_15 -> V_24 , & V_30 ) ;
F_12 ( & V_23 ) ;
}
if ( ( V_16 = F_13 ( V_6 , V_26 ) ) == NULL ) {
goto V_22;
}
F_14 ( V_16 , V_10 ) ;
V_18 = 1 ;
V_22:
F_15 ( V_10 ) ;
V_21:
F_16 ( V_9 ) ;
V_19:
return V_18 ;
}
int F_17 ( int V_7 , struct V_3 * V_4 , struct V_5 * V_6 ) {
struct V_13 * V_31 ;
struct V_11 * V_12 ;
struct V_32 * V_33 = NULL ;
struct V_3 * V_34 ;
struct V_5 * V_16 ;
int V_18 = 0 ;
F_4 ( & V_23 ) ;
F_5 (entry, &x25_forward_list) {
V_31 = F_6 ( V_12 , struct V_13 , V_24 ) ;
if ( V_31 -> V_7 == V_7 ) {
if ( V_4 -> V_20 == V_31 -> V_28 ) {
V_33 = V_31 -> V_29 ;
} else {
V_33 = V_31 -> V_28 ;
}
break;
}
}
F_8 ( & V_23 ) ;
if ( ( V_34 = F_3 ( V_33 ) ) == NULL )
goto V_35;
if ( ( V_16 = F_18 ( V_6 , V_26 ) ) == NULL ) {
goto V_36;
}
F_14 ( V_16 , V_34 ) ;
V_18 = 1 ;
V_36:
F_15 ( V_34 ) ;
V_35:
return V_18 ;
}
void F_19 ( unsigned int V_7 )
{
struct V_13 * V_37 ;
struct V_11 * V_12 , * V_38 ;
F_10 ( & V_23 ) ;
F_20 (entry, tmp, &x25_forward_list) {
V_37 = F_6 ( V_12 , struct V_13 , V_24 ) ;
if ( V_37 -> V_7 == V_7 ) {
F_21 ( & V_37 -> V_24 ) ;
F_22 ( V_37 ) ;
}
}
F_12 ( & V_23 ) ;
}
void F_23 ( struct V_32 * V_20 )
{
struct V_13 * V_37 ;
struct V_11 * V_12 , * V_38 ;
F_10 ( & V_23 ) ;
F_20 (entry, tmp, &x25_forward_list) {
V_37 = F_6 ( V_12 , struct V_13 , V_24 ) ;
if ( ( V_37 -> V_28 == V_20 ) || ( V_37 -> V_29 == V_20 ) ) {
F_21 ( & V_37 -> V_24 ) ;
F_22 ( V_37 ) ;
}
}
F_12 ( & V_23 ) ;
}
