T_1 F_1 ( struct V_1 * V_2 , T_2 * V_3 )
{
return fprintf ( V_3 , L_1 V_4 L_2 V_4 L_3 ,
V_2 -> V_5 , V_2 -> V_6 ,
V_2 -> V_7 == V_8 ? 'g' :
V_2 -> V_7 == V_9 ? 'l' : 'w' ,
V_2 -> V_10 ) ;
}
T_1 F_2 ( const struct V_1 * V_2 ,
const struct V_11 * V_12 ,
bool V_13 ,
bool V_14 , T_2 * V_3 )
{
unsigned long V_15 ;
T_1 V_16 ;
if ( V_2 && V_2 -> V_10 ) {
V_16 = fprintf ( V_3 , L_4 , V_2 -> V_10 ) ;
if ( V_12 && V_14 ) {
if ( V_12 -> V_17 < V_2 -> V_6 )
V_15 = V_12 -> V_17 - V_2 -> V_5 ;
else
V_15 = V_12 -> V_17 - V_12 -> V_18 -> V_5 - V_2 -> V_5 ;
V_16 += fprintf ( V_3 , L_5 , V_15 ) ;
}
return V_16 ;
} else if ( V_12 && V_13 )
return fprintf ( V_3 , L_6 V_4 L_7 , V_12 -> V_17 ) ;
else
return fprintf ( V_3 , L_8 ) ;
}
T_1 F_3 ( const struct V_1 * V_2 ,
const struct V_11 * V_12 ,
T_2 * V_3 )
{
return F_2 ( V_2 , V_12 , false , true , V_3 ) ;
}
T_1 F_4 ( const struct V_1 * V_2 ,
const struct V_11 * V_12 ,
bool V_13 , T_2 * V_3 )
{
return F_2 ( V_2 , V_12 , V_13 , false , V_3 ) ;
}
T_1 F_5 ( const struct V_1 * V_2 , T_2 * V_3 )
{
return F_2 ( V_2 , NULL , false , false , V_3 ) ;
}
T_1 F_6 ( struct V_19 * V_19 ,
enum V_20 type , T_2 * V_3 )
{
T_1 V_21 = 0 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
for ( V_23 = F_7 ( & V_19 -> V_26 [ type ] ) ; V_23 ; V_23 = F_8 ( V_23 ) ) {
V_25 = F_9 ( V_23 , struct V_24 , V_22 ) ;
fprintf ( V_3 , L_9 , V_25 -> V_2 . V_10 ) ;
}
return V_21 ;
}
