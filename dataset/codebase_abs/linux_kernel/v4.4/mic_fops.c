int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 = F_2 ( V_3 -> V_8 ,
struct V_6 , V_9 ) ;
V_5 = F_3 ( sizeof( * V_5 ) , V_10 ) ;
if ( ! V_5 )
return - V_11 ;
F_4 ( & V_5 -> V_12 ) ;
F_5 ( & V_5 -> V_13 ) ;
V_5 -> V_7 = V_7 ;
V_5 -> V_14 = - 1 ;
V_3 -> V_8 = V_5 ;
return 0 ;
}
int F_6 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_8 ;
if ( - 1 != V_5 -> V_14 )
F_7 ( V_5 ) ;
V_3 -> V_8 = NULL ;
F_8 ( V_5 ) ;
return 0 ;
}
long F_9 ( struct V_2 * V_3 , unsigned int V_15 , unsigned long V_16 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_8 ;
void T_1 * V_17 = ( void T_1 * ) V_16 ;
int V_18 ;
switch ( V_15 ) {
case V_19 :
{
V_18 = F_10 ( V_5 , V_17 ) ;
if ( V_18 < 0 ) {
F_11 ( F_12 ( V_5 ) ,
L_1 ,
V_20 , __LINE__ , V_18 ) ;
return V_18 ;
}
break;
}
case V_21 :
{
struct V_22 V_23 ;
V_18 = F_13 ( V_5 ) ;
if ( V_18 )
return V_18 ;
if ( F_14 ( & V_23 , V_17 , sizeof( V_23 ) ) )
return - V_24 ;
F_15 ( F_12 ( V_5 ) ,
L_2 ,
V_20 , __LINE__ , V_23 . V_25 , V_23 . V_26 ,
V_23 . V_27 ) ;
V_18 = F_16 ( V_5 , & V_23 ) ;
if ( V_18 < 0 ) {
F_11 ( F_12 ( V_5 ) ,
L_1 ,
V_20 , __LINE__ , V_18 ) ;
return V_18 ;
}
if ( F_17 (
& ( (struct V_22 T_1 * ) V_17 ) -> V_28 ,
& V_23 . V_28 , sizeof( V_23 . V_28 ) ) ) {
F_11 ( F_12 ( V_5 ) , L_1 ,
V_20 , __LINE__ , - V_24 ) ;
return - V_24 ;
}
break;
}
case V_29 :
{
V_18 = F_13 ( V_5 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_18 ( V_5 , V_17 ) ;
if ( V_18 < 0 ) {
F_11 ( F_12 ( V_5 ) ,
L_1 ,
V_20 , __LINE__ , V_18 ) ;
return V_18 ;
}
break;
}
default:
return - V_30 ;
} ;
return 0 ;
}
unsigned int F_19 ( struct V_2 * V_3 , T_2 * V_31 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_8 ;
int V_32 = 0 ;
F_20 ( V_3 , & V_5 -> V_12 , V_31 ) ;
if ( F_13 ( V_5 ) ) {
V_32 = V_33 ;
} else if ( V_5 -> V_34 ) {
V_5 -> V_34 = 0 ;
V_32 = V_35 | V_36 ;
}
return V_32 ;
}
static inline int
F_21 ( struct V_4 * V_5 , unsigned long V_37 ,
unsigned long * V_38 , unsigned long * V_39 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
unsigned long V_40 = V_41 ;
int V_42 ;
if ( ! V_37 ) {
* V_39 = F_22 ( V_7 -> V_43 ) ;
* V_38 = V_41 ;
return 0 ;
}
for ( V_42 = 0 ; V_42 < V_5 -> V_44 -> V_45 ; V_42 ++ ) {
struct V_46 * V_47 = & V_5 -> V_47 [ V_42 ] ;
if ( V_37 == V_40 ) {
* V_39 = F_22 ( V_47 -> V_48 . V_49 ) ;
* V_38 = V_47 -> V_48 . V_50 ;
return 0 ;
}
V_40 += V_47 -> V_48 . V_50 ;
}
return - 1 ;
}
int
F_23 ( struct V_2 * V_3 , struct V_51 * V_52 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_8 ;
unsigned long V_37 = V_52 -> V_53 << V_54 ;
unsigned long V_39 , V_38 = V_52 -> V_55 - V_52 -> V_56 , V_57 = V_38 ;
int V_42 , V_58 ;
V_58 = F_13 ( V_5 ) ;
if ( V_58 )
return V_58 ;
if ( V_52 -> V_59 & V_60 )
return - V_61 ;
while ( V_57 ) {
V_42 = F_21 ( V_5 , V_37 , & V_38 , & V_39 ) ;
if ( V_42 < 0 )
return - V_62 ;
V_58 = F_24 ( V_52 , V_52 -> V_56 + V_37 ,
V_39 >> V_54 , V_38 , V_52 -> V_63 ) ;
if ( V_58 )
return V_58 ;
F_15 ( F_12 ( V_5 ) ,
L_3 ,
V_20 , __LINE__ , V_5 -> V_14 , V_38 , V_37 ,
V_39 , V_52 -> V_56 + V_37 ) ;
V_57 -= V_38 ;
V_37 += V_38 ;
}
return 0 ;
}
