void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_6 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_2 ( & V_4 -> V_7 ) ;
F_3 ( & V_4 -> V_8 , V_9 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
}
int F_5 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
T_1 * V_12 , int V_13 ,
T_1 * V_14 , int V_15 ,
T_2 V_16 , void * V_17 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_6 ;
T_1 V_18 [ F_6 ( V_19 ) ] = { 0 } ;
T_1 V_20 ;
void * V_21 ;
int V_22 ;
T_3 V_23 ;
F_7 ( & V_2 -> V_5 . V_24 ) ;
V_23 = V_2 -> V_5 . V_25 ++ ;
F_8 ( & V_2 -> V_5 . V_24 ) ;
V_21 = F_9 ( V_26 , V_12 , V_27 ) ;
F_10 ( V_26 , V_12 , V_28 , V_29 ) ;
F_10 ( V_21 , V_21 , V_30 , V_23 ) ;
if ( V_16 )
return F_11 ( V_2 , V_12 , V_13 , V_14 , V_15 ,
V_16 , V_17 ) ;
V_22 = F_12 ( V_2 , V_12 , V_13 , V_18 , sizeof( V_18 ) ) ;
if ( V_22 )
return V_22 ;
V_20 = F_13 ( V_19 , V_18 , V_20 ) ;
V_11 -> V_31 = F_14 ( V_21 , V_21 , V_32 ) ;
V_11 -> V_33 = F_14 ( V_21 , V_21 , V_34 ) ;
V_11 -> V_23 = F_15 ( V_20 ) | V_23 ;
V_11 -> V_35 = F_13 ( V_21 , V_21 , V_35 ) ;
F_16 ( V_2 , L_1 ,
V_20 , V_23 , V_11 -> V_23 ) ;
F_17 ( & V_4 -> V_7 ) ;
V_22 = F_18 ( & V_4 -> V_8 , F_19 ( V_11 -> V_23 ) , V_11 ) ;
F_20 ( & V_4 -> V_7 ) ;
if ( V_22 ) {
F_21 ( V_2 , L_2 ,
F_19 ( V_11 -> V_23 ) , V_22 ) ;
F_22 ( V_2 , V_11 ) ;
}
return V_22 ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
T_1 * V_12 , int V_13 )
{
return F_5 ( V_2 , V_11 , V_12 , V_13 ,
NULL , 0 , NULL , NULL ) ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_6 ;
T_1 V_14 [ F_6 ( V_36 ) ] = { 0 } ;
T_1 V_12 [ F_6 ( V_37 ) ] = { 0 } ;
struct V_10 * V_38 ;
unsigned long V_39 ;
F_24 ( & V_4 -> V_7 , V_39 ) ;
V_38 = F_25 ( & V_4 -> V_8 , F_19 ( V_11 -> V_23 ) ) ;
F_26 ( & V_4 -> V_7 , V_39 ) ;
if ( ! V_38 ) {
F_21 ( V_2 , L_3 ,
F_19 ( V_11 -> V_23 ) ) ;
return - V_40 ;
}
F_10 ( V_37 , V_12 , V_28 , V_41 ) ;
F_10 ( V_37 , V_12 , V_20 , F_27 ( V_11 -> V_23 ) ) ;
return F_12 ( V_2 , V_12 , sizeof( V_12 ) , V_14 , sizeof( V_14 ) ) ;
}
int F_28 ( struct V_1 * V_2 , struct V_10 * V_11 ,
T_1 * V_14 , int V_15 )
{
T_1 V_12 [ F_6 ( V_42 ) ] = { 0 } ;
memset ( V_14 , 0 , V_15 ) ;
F_10 ( V_42 , V_12 , V_28 , V_43 ) ;
F_10 ( V_42 , V_12 , V_20 , F_27 ( V_11 -> V_23 ) ) ;
return F_12 ( V_2 , V_12 , sizeof( V_12 ) , V_14 , V_15 ) ;
}
int F_29 ( struct V_1 * V_2 , struct V_10 * V_44 ,
T_1 * V_11 )
{
T_1 V_14 [ F_6 ( V_45 ) ] = { 0 } ;
T_1 V_12 [ F_6 ( V_46 ) ] = { 0 } ;
int V_22 ;
F_10 ( V_46 , V_12 , V_28 ,
V_47 ) ;
V_22 = F_12 ( V_2 , V_12 , sizeof( V_12 ) , V_14 , sizeof( V_14 ) ) ;
if ( ! V_22 )
* V_11 = F_13 ( V_45 , V_14 ,
V_48 ) ;
return V_22 ;
}
static inline T_1 F_30 ( T_1 * V_14 , int V_49 )
{
switch ( V_49 ) {
case 1 : return F_13 ( V_50 , V_14 , V_51 ) ;
case 2 : return F_13 ( V_50 , V_14 , V_52 ) ;
case 3 : return F_13 ( V_50 , V_14 , V_53 ) ;
default: return F_13 ( V_50 , V_14 , V_54 ) ;
}
}
int F_31 ( struct V_1 * V_2 , T_1 V_55 ,
int V_56 , T_1 * V_57 )
{
T_1 V_14 [ F_6 ( V_50 ) ] = { 0 } ;
T_1 V_12 [ F_6 ( V_58 ) ] = { 0 } ;
int V_59 , V_22 ;
if ( V_56 > V_60 )
return - V_61 ;
F_10 ( V_58 , V_12 , V_28 , V_62 ) ;
F_10 ( V_58 , V_12 , V_35 , V_55 ) ;
F_10 ( V_58 , V_12 , V_63 , V_56 ) ;
V_22 = F_12 ( V_2 , V_12 , sizeof( V_12 ) , V_14 , sizeof( V_14 ) ) ;
if ( V_22 )
return V_22 ;
for ( V_59 = 0 ; V_59 < V_56 ; V_59 ++ )
V_57 [ V_59 ] = F_30 ( V_14 , V_59 ) ;
return V_22 ;
}
int F_32 ( struct V_1 * V_2 , int V_64 )
{
T_1 V_14 [ F_6 ( V_65 ) ] = { 0 } ;
T_1 V_12 [ F_6 ( V_66 ) ] = { 0 } ;
F_10 ( V_66 , V_12 , V_28 , V_67 ) ;
F_10 ( V_66 , V_12 , V_68 , V_64 ) ;
return F_12 ( V_2 , V_12 , sizeof( V_12 ) , V_14 , sizeof( V_14 ) ) ;
}
