int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 ,
char * V_6 ,
unsigned int * V_7 )
{
struct V_3 * V_8 = NULL ;
struct V_3 * V_9 = NULL ;
int V_10 = V_6 ? strlen ( V_6 ) : 0 ;
unsigned int V_11 ;
V_11 = F_2 ( V_4 , V_6 ,
& V_8 , & V_9 ) ;
V_11 &= ~ V_12 ;
if ( V_10 && ! V_8 && ! V_9 ) {
F_3 ( V_2 , L_1 ) ;
V_11 = F_2 ( V_5 , NULL , NULL , NULL ) |
( V_11 & ~ V_13 ) ;
} else {
if ( V_5 == V_8 )
V_11 |= ( V_5 == V_9 ) ?
V_14 : V_15 ;
else
V_11 |= ( V_5 == V_9 ) ?
V_16 : V_17 ;
}
F_4 ( V_8 ) ;
F_4 ( V_9 ) ;
* V_7 = V_11 ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
const char * V_20 , ... )
{
T_1 V_21 ;
char * V_22 = NULL ;
int V_23 = - V_24 ;
va_start ( V_21 , V_20 ) ;
V_22 = F_6 ( V_2 , V_25 , V_20 , V_21 ) ;
va_end ( V_21 ) ;
if ( V_22 ) {
V_23 = 0 ;
V_19 -> V_22 = V_22 ;
V_19 -> V_26 = V_22 ;
}
return V_23 ;
}
int F_7 ( struct V_27 * V_28 ,
char * V_6 )
{
char V_29 [ 128 ] ;
int V_23 ;
snprintf ( V_29 , sizeof( V_29 ) , L_2 , V_6 ) ;
V_23 = F_8 ( V_28 , V_29 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( ! V_28 -> V_22 && V_28 -> V_19 )
V_28 -> V_22 = V_28 -> V_19 -> V_22 ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_30 ,
struct V_31 * V_32 )
{
struct V_33 * V_33 ;
T_2 V_34 ;
V_33 = F_10 ( V_2 , V_4 , NULL ) ;
if ( ! F_11 ( V_33 ) ) {
V_32 -> V_35 = F_12 ( V_33 ) ;
V_32 -> V_33 = V_33 ;
} else if ( ! F_13 ( V_4 , L_3 , & V_34 ) ) {
V_32 -> V_35 = V_34 ;
} else {
V_33 = F_10 ( V_2 , V_30 , NULL ) ;
if ( ! F_11 ( V_33 ) )
V_32 -> V_35 = F_12 ( V_33 ) ;
}
return 0 ;
}
int F_14 ( struct V_3 * V_4 ,
struct V_3 * * V_30 ,
const char * * V_36 ,
const char * V_37 ,
const char * V_38 ,
int * V_39 )
{
struct V_40 args ;
int V_23 ;
if ( ! V_4 )
return 0 ;
V_23 = F_15 ( V_4 , V_37 , V_38 , 0 , & args ) ;
if ( V_23 )
return V_23 ;
if ( V_36 ) {
V_23 = F_16 ( V_4 , V_36 ) ;
if ( V_23 < 0 )
return V_23 ;
}
* V_30 = args . V_41 ;
if ( V_39 )
* V_39 = ! args . V_42 ;
return 0 ;
}
int F_17 ( struct V_43 * V_44 ,
struct V_31 * V_32 )
{
int V_23 ;
if ( V_32 -> V_35 ) {
V_23 = F_18 ( V_44 , 0 , V_32 -> V_35 , 0 ) ;
if ( V_23 && V_23 != - V_45 ) {
F_19 ( V_44 -> V_2 , L_4 ) ;
return V_23 ;
}
}
if ( V_32 -> V_46 ) {
V_23 = F_20 ( V_44 ,
V_32 -> V_47 ,
V_32 -> V_48 ,
V_32 -> V_46 ,
V_32 -> V_49 ) ;
if ( V_23 && V_23 != - V_45 ) {
F_19 ( V_44 -> V_2 , L_5 ) ;
return V_23 ;
}
}
return 0 ;
}
int F_21 ( struct V_18 * V_19 )
{
if ( ! V_19 -> V_50 )
V_19 -> V_50 = V_19 -> V_51 ;
return 0 ;
}
void F_22 ( struct V_18 * V_19 ,
int V_52 )
{
if ( V_52 )
V_19 -> V_53 = NULL ;
}
int F_23 ( struct V_27 * V_28 )
{
struct V_18 * V_19 ;
int V_54 ;
for ( V_54 = 0 , V_19 = V_28 -> V_19 ;
V_54 < V_28 -> V_54 ;
V_54 ++ , V_19 ++ ) {
F_4 ( V_19 -> V_51 ) ;
F_4 ( V_19 -> V_55 ) ;
}
return 0 ;
}
