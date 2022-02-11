static T_1 F_1 ( struct V_1 * V_2 , const T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_2 V_7 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
V_7 = F_3 ( V_3 ) * 128ULL ;
return F_4 ( V_7 , 100000 ) ;
}
static T_3
F_5 ( struct V_8 * V_2 , struct V_9 * V_10 , char * V_11 )
{
struct V_12 * V_13 = F_6 ( V_2 , struct V_12 , V_14 ) ;
return snprintf ( V_11 , V_15 , L_1 , F_2 ( V_13 -> V_2 ) ) ;
}
static T_3
F_7 ( struct V_8 * V_2 , struct V_9 * V_10 , char * V_11 )
{
struct V_12 * V_13 = F_6 ( V_2 , struct V_12 , V_14 ) ;
T_1 V_16 = F_1 ( V_13 -> V_2 , V_17 ) ;
return snprintf ( V_11 , V_15 , L_2 , V_16 ) ;
}
static T_3
F_8 ( struct V_8 * V_2 , struct V_9 * V_10 , char * V_11 )
{
struct V_12 * V_13 = F_6 ( V_2 , struct V_12 , V_14 ) ;
T_1 V_18 = F_1 ( V_13 -> V_2 , V_19 ) ;
return snprintf ( V_11 , V_15 , L_2 , V_18 ) ;
}
static T_3
F_9 ( struct V_8 * V_2 , struct V_9 * V_10 , char * V_11 )
{
struct V_12 * V_13 = F_6 ( V_2 , struct V_12 , V_14 ) ;
T_1 V_20 = F_1 ( V_13 -> V_2 , V_21 ) ;
return snprintf ( V_11 , V_15 , L_2 , V_20 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_4 V_22 )
{
if ( ! F_11 ( V_2 ) )
return - V_23 ;
if ( V_22 % 4 != 0 )
return - V_24 ;
if ( V_22 >= V_25 )
return - V_26 ;
return 0 ;
}
static T_3
F_12 ( struct V_27 * V_28 , struct V_29 * V_30 ,
struct V_31 * V_10 , char * V_11 ,
T_4 V_22 , T_5 V_32 )
{
struct V_8 * V_2 = F_6 ( V_30 , struct V_8 , V_30 ) ;
struct V_12 * V_13 = F_6 ( V_2 , struct V_12 , V_14 ) ;
struct V_1 * V_33 = V_13 -> V_2 ;
struct V_4 * V_5 = V_33 -> V_6 ;
T_6 V_34 ;
int V_35 , V_36 ;
V_36 = F_10 ( V_33 , V_22 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_13 ( V_33 ) ;
if ( V_36 )
return V_36 ;
V_34 = F_3 ( V_37 ) ;
F_14 ( V_37 , V_34 & ~ V_38 ) ;
for ( V_35 = V_22 ; V_32 >= 4 && V_35 < V_25 ; V_35 += 4 , V_32 -= 4 )
* ( ( T_6 * ) ( & V_11 [ V_35 ] ) ) = F_3 ( V_39 + V_35 ) ;
F_14 ( V_37 , V_34 ) ;
F_15 ( & V_33 -> V_40 ) ;
return V_35 - V_22 ;
}
static T_3
F_16 ( struct V_27 * V_28 , struct V_29 * V_30 ,
struct V_31 * V_10 , char * V_11 ,
T_4 V_22 , T_5 V_32 )
{
struct V_8 * V_2 = F_6 ( V_30 , struct V_8 , V_30 ) ;
struct V_12 * V_13 = F_6 ( V_2 , struct V_12 , V_14 ) ;
struct V_1 * V_33 = V_13 -> V_2 ;
struct V_4 * V_5 = V_33 -> V_6 ;
T_1 * V_41 = NULL ;
int V_36 ;
V_36 = F_10 ( V_33 , V_22 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_13 ( V_33 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_5 -> V_42 . V_43 ) {
V_41 = F_17 ( V_25 , V_44 ) ;
if ( ! V_41 ) {
F_15 ( & V_33 -> V_40 ) ;
return - V_45 ;
}
}
V_36 = F_18 ( V_33 ) ;
if ( V_36 ) {
F_19 ( V_41 ) ;
F_15 ( & V_33 -> V_40 ) ;
return V_36 ;
}
if ( V_41 )
V_5 -> V_42 . V_43 = V_41 ;
memcpy ( V_5 -> V_42 . V_43 + ( V_22 / 4 ) ,
V_11 + ( V_22 / 4 ) ,
V_32 ) ;
F_20 ( V_33 ) ;
F_15 ( & V_33 -> V_40 ) ;
return V_32 ;
}
void F_21 ( struct V_1 * V_2 )
{
int V_36 ;
if ( F_22 ( V_2 ) -> V_46 >= 6 ) {
V_36 = F_23 ( & V_2 -> V_47 -> V_14 . V_30 ,
& V_48 ) ;
if ( V_36 )
F_24 ( L_3 ) ;
}
if ( F_11 ( V_2 ) ) {
V_36 = F_25 ( & V_2 -> V_47 -> V_14 , & V_49 ) ;
if ( V_36 )
F_24 ( L_4 ) ;
}
}
void F_26 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_47 -> V_14 , & V_49 ) ;
F_28 ( & V_2 -> V_47 -> V_14 . V_30 , & V_48 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
return;
}
void F_26 ( struct V_1 * V_2 )
{
return;
}
