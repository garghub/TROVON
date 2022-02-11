const struct V_1 * F_1 ( const struct V_1 * V_2 )
{
const struct V_1 * V_3 ;
struct V_4 * V_5 = & V_6 ;
for ( V_3 = V_2 ; V_3 -> V_7 | V_3 -> V_8 | V_3 -> V_9 | V_3 -> V_10 ; V_3 ++ ) {
if ( V_3 -> V_7 != V_11 && V_5 -> V_12 != V_3 -> V_7 )
continue;
if ( V_3 -> V_8 != V_13 && V_5 -> V_14 != V_3 -> V_8 )
continue;
if ( V_3 -> V_9 != V_15 && V_5 -> V_16 != V_3 -> V_9 )
continue;
if ( V_3 -> V_10 != V_17 && ! F_2 ( V_5 , V_3 -> V_10 ) )
continue;
return V_3 ;
}
return NULL ;
}
T_1 F_3 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
char * V_22 )
{
int V_23 = V_24 ;
int V_25 , V_26 ;
char * V_27 = V_22 ;
V_26 = snprintf ( V_27 , V_23 , L_1
L_2 ,
V_6 . V_12 ,
V_6 . V_14 ,
V_6 . V_16 ) ;
V_23 -= V_26 ;
V_27 += V_26 ;
V_23 -= 1 ;
for ( V_25 = 0 ; V_25 < V_28 * 32 ; V_25 ++ ) {
if ( F_4 ( V_25 ) ) {
V_26 = snprintf ( V_27 , V_23 , L_3 , V_25 ) ;
if ( V_26 >= V_23 ) {
F_5 ( 1 , L_4 ) ;
break;
}
V_23 -= V_26 ;
V_27 += V_26 ;
}
}
* V_27 ++ = '\n' ;
return V_27 - V_22 ;
}
int F_6 ( struct V_18 * V_19 , struct V_29 * V_30 )
{
char * V_27 = F_7 ( V_24 , V_31 ) ;
if ( V_27 ) {
F_3 ( NULL , NULL , V_27 ) ;
F_8 ( V_30 , L_5 , V_27 ) ;
F_9 ( V_27 ) ;
}
return 0 ;
}
