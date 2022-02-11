static T_1
F_1 ( T_2 * V_1 , T_3 V_2 , int * V_3 , T_4 * * V_4 )
{
if ( ! F_2 ( V_2 , V_1 , V_5 , V_3 , V_4 ) )
return FALSE ;
V_1 -> V_6 = F_3 ( V_1 -> V_6 ) ;
V_1 -> V_7 = F_3 ( V_1 -> V_7 ) ;
V_1 -> V_8 = F_4 ( V_1 -> V_8 ) ;
V_1 -> V_9 = F_4 ( V_1 -> V_9 ) ;
V_1 -> V_10 = F_4 ( V_1 -> V_10 ) ;
if ( V_1 -> V_6 != V_11 ) {
* V_3 = V_12 ;
* V_4 = F_5 ( L_1 , V_1 -> V_6 ) ;
return FALSE ;
}
if ( V_1 -> V_7 < 16 ) {
* V_3 = V_12 ;
* V_4 = F_5 ( L_2 , V_1 -> V_7 ) ;
return FALSE ;
}
if ( F_6 ( V_2 , 0 - V_5 , V_13 , V_3 ) == - 1 ) {
F_7 ( L_3 ) ;
return FALSE ;
}
return TRUE ;
}
static T_1
F_8 ( T_3 V_2 , struct V_14 * V_15 , T_5 * V_16 , int * V_3 , T_4 * * V_4 )
{
T_2 V_17 ;
if ( ! F_1 ( & V_17 , V_2 , V_3 , V_4 ) )
return FALSE ;
V_15 -> V_18 = V_19 ;
V_15 -> V_20 = V_21 ;
V_15 -> V_22 = V_17 . V_7 ;
V_15 -> V_23 = V_17 . V_7 ;
V_15 -> V_24 . V_25 = V_17 . V_8 ;
V_15 -> V_24 . V_26 = 0 ;
return F_9 ( V_2 , V_16 , V_17 . V_7 , V_3 , V_4 ) ;
}
int
F_10 ( T_6 * V_27 , int * V_3 , T_4 * * V_4 )
{
T_7 V_28 , V_29 , V_30 = V_31 ;
T_4 * V_32 ;
T_8 V_33 = 0 ;
T_2 V_17 ;
T_9 V_34 ;
F_7 ( L_4 ) ;
if ( ( V_32 = getenv ( L_5 ) ) != NULL ) {
if ( ( V_29 = atoi ( V_32 ) ) > 0 && V_29 < 101 ) {
V_30 = V_29 ;
}
}
for ( V_28 = 0 ; V_28 < V_30 ; V_28 ++ ) {
if ( ! F_1 ( & V_17 , V_27 -> V_2 , V_3 , V_4 ) ) {
F_11 ( L_6 ,
V_28 , * V_3 , * V_4 ) ;
if ( * V_3 == V_12 ) {
* V_3 = 0 ;
F_12 ( * V_4 ) ;
* V_4 = NULL ;
return 0 ;
}
if ( * V_3 != 0 && * V_3 != V_35 )
return - 1 ;
if ( V_28 < 1 ) {
return 0 ;
}
break;
}
if ( F_6 ( V_27 -> V_2 , V_5 , V_13 , V_3 ) == - 1 ) {
F_13 ( L_7 ,
V_17 . V_7 ) ;
return 0 ;
}
V_33 = V_5 ;
while ( V_33 < V_17 . V_7 ) {
if ( ! F_14 ( V_27 -> V_2 , & V_34 , V_36 ,
V_3 , V_4 ) ) {
if ( * V_3 == V_35 ) {
F_13 ( L_8 , * V_3 ) ;
return 0 ;
}
return - 1 ;
}
V_34 . V_37 = F_3 ( V_34 . V_37 ) ;
if ( ( V_34 . V_37 < V_36 ) ||
( ( V_34 . V_37 + V_33 ) > V_17 . V_7 ) ) {
F_13 ( L_9 ,
V_34 . V_37 ) ;
return 0 ;
}
if ( F_6 ( V_27 -> V_2 , V_34 . V_37 - V_36 ,
V_13 , V_3 ) == - 1 )
{
F_13 ( L_10 ,
V_34 . V_37 - V_36 ) ;
return - 1 ;
}
V_33 += V_34 . V_37 ;
}
}
V_27 -> V_38 = V_39 ;
V_27 -> V_40 = 0 ;
V_27 -> V_41 = V_42 ;
V_27 -> V_43 = V_44 ;
V_27 -> V_45 = V_46 ;
V_27 -> V_47 = V_48 ;
V_27 -> V_49 = V_50 ;
if ( F_6 ( V_27 -> V_2 , 0 , V_51 , V_3 ) != 0 )
{
return - 1 ;
}
return 1 ;
}
static T_1
V_44 ( T_6 * V_27 , int * V_3 , T_4 * * V_4 , T_10 * V_52 )
{
* V_52 = F_15 ( V_27 -> V_2 ) ;
F_13 ( L_11 V_53 L_12 , * V_52 ) ;
if ( ! F_8 ( V_27 -> V_2 , & V_27 -> V_15 , V_27 -> V_54 , V_3 , V_4 ) ) {
F_16 ( L_13 ,
* V_3 , * V_4 ) ;
return FALSE ;
}
return TRUE ;
}
static T_1
V_46 ( T_6 * V_27 , T_10 V_55 , struct V_14 * V_15 ,
T_5 * V_16 , int * V_3 , T_4 * * V_4 )
{
if ( F_6 ( V_27 -> V_56 , V_55 , V_51 , V_3 ) == - 1 ) {
F_16 ( L_14 ,
* V_3 , * V_4 ) ;
return FALSE ;
}
F_13 ( L_15 V_53 L_16 , V_55 ) ;
if ( ! F_8 ( V_27 -> V_56 , V_15 , V_16 , V_3 , V_4 ) ) {
F_7 ( L_17 ) ;
if ( * V_3 == 0 )
* V_3 = V_35 ;
return FALSE ;
}
return TRUE ;
}
static void
V_48 ( T_6 * V_27 V_57 )
{
F_7 ( L_18 ) ;
}
