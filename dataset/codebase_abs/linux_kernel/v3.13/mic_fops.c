int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 = F_2 ( V_1 -> V_8 ,
struct V_6 , V_9 ) ;
V_5 = F_3 ( sizeof( * V_5 ) , V_10 ) ;
if ( ! V_5 )
return - V_11 ;
F_4 ( & V_5 -> V_12 ) ;
F_5 ( & V_5 -> V_13 ) ;
V_5 -> V_7 = V_7 ;
V_5 -> V_14 = - 1 ;
V_3 -> V_15 = V_5 ;
return 0 ;
}
int F_6 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_15 ;
if ( - 1 != V_5 -> V_14 )
F_7 ( V_5 ) ;
V_3 -> V_15 = NULL ;
F_8 ( V_5 ) ;
return 0 ;
}
long F_9 ( struct V_2 * V_3 , unsigned int V_16 , unsigned long V_17 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_15 ;
void T_1 * V_18 = ( void T_1 * ) V_17 ;
int V_19 ;
switch ( V_16 ) {
case V_20 :
{
V_19 = F_10 ( V_5 , V_18 ) ;
if ( V_19 < 0 ) {
F_11 ( F_12 ( V_5 ) ,
L_1 ,
V_21 , __LINE__ , V_19 ) ;
return V_19 ;
}
break;
}
case V_22 :
{
struct V_23 V_24 ;
V_19 = F_13 ( V_5 ) ;
if ( V_19 )
return V_19 ;
if ( F_14 ( & V_24 , V_18 , sizeof( V_24 ) ) )
return - V_25 ;
F_15 ( F_12 ( V_5 ) ,
L_2 ,
V_21 , __LINE__ , V_24 . V_26 , V_24 . V_27 ,
V_24 . V_28 ) ;
V_19 = F_16 ( V_5 , & V_24 ) ;
if ( V_19 < 0 ) {
F_11 ( F_12 ( V_5 ) ,
L_1 ,
V_21 , __LINE__ , V_19 ) ;
return V_19 ;
}
if ( F_17 (
& ( (struct V_23 T_1 * ) V_18 ) -> V_29 ,
& V_24 . V_29 , sizeof( V_24 . V_29 ) ) ) {
F_11 ( F_12 ( V_5 ) , L_1 ,
V_21 , __LINE__ , - V_25 ) ;
return - V_25 ;
}
break;
}
case V_30 :
{
V_19 = F_13 ( V_5 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_18 ( V_5 , V_18 ) ;
if ( V_19 < 0 ) {
F_11 ( F_12 ( V_5 ) ,
L_1 ,
V_21 , __LINE__ , V_19 ) ;
return V_19 ;
}
break;
}
default:
return - V_31 ;
} ;
return 0 ;
}
unsigned int F_19 ( struct V_2 * V_3 , T_2 * V_32 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_15 ;
int V_33 = 0 ;
F_20 ( V_3 , & V_5 -> V_12 , V_32 ) ;
if ( F_13 ( V_5 ) ) {
V_33 = V_34 ;
} else if ( V_5 -> V_35 ) {
V_5 -> V_35 = 0 ;
V_33 = V_36 | V_37 ;
}
return V_33 ;
}
static inline int
F_21 ( struct V_4 * V_5 , unsigned long V_38 ,
unsigned long * V_39 , unsigned long * V_40 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
unsigned long V_41 = V_42 ;
int V_43 ;
if ( ! V_38 ) {
* V_40 = F_22 ( V_7 -> V_44 ) ;
* V_39 = V_42 ;
return 0 ;
}
for ( V_43 = 0 ; V_43 < V_5 -> V_45 -> V_46 ; V_43 ++ ) {
struct V_47 * V_48 = & V_5 -> V_48 [ V_43 ] ;
if ( V_38 == V_41 ) {
* V_40 = F_22 ( V_48 -> V_49 . V_50 ) ;
* V_39 = V_48 -> V_49 . V_51 ;
return 0 ;
}
V_41 += V_48 -> V_49 . V_51 ;
}
return - 1 ;
}
int
F_23 ( struct V_2 * V_3 , struct V_52 * V_53 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_15 ;
unsigned long V_38 = V_53 -> V_54 << V_55 ;
unsigned long V_40 , V_39 = V_53 -> V_56 - V_53 -> V_57 , V_58 = V_39 ;
int V_43 , V_59 ;
V_59 = F_13 ( V_5 ) ;
if ( V_59 )
return V_59 ;
if ( V_53 -> V_60 & V_61 )
return - V_62 ;
while ( V_58 ) {
V_43 = F_21 ( V_5 , V_38 , & V_39 , & V_40 ) ;
if ( V_43 < 0 )
return - V_63 ;
V_59 = F_24 ( V_53 , V_53 -> V_57 + V_38 ,
V_40 >> V_55 , V_39 , V_53 -> V_64 ) ;
if ( V_59 )
return V_59 ;
F_15 ( F_12 ( V_5 ) ,
L_3 ,
V_21 , __LINE__ , V_5 -> V_14 , V_39 , V_38 ,
V_40 , V_53 -> V_57 + V_38 ) ;
V_58 -= V_39 ;
V_38 += V_39 ;
}
return 0 ;
}
