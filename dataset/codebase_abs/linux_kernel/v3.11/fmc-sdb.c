static T_1 F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
int V_4 )
{
T_1 V_5 = F_2 ( V_2 , V_3 ) ;
if ( V_4 )
return F_3 ( V_5 ) ;
return V_5 ;
}
static struct V_6 * F_4 ( struct V_1 * V_2 ,
unsigned long V_7 ,
unsigned long V_8 , int V_9 )
{
T_1 V_10 ;
int V_11 , V_12 , V_13 , V_4 = 0 ;
struct V_6 * V_14 , * V_15 ;
V_10 = F_2 ( V_2 , V_7 ) ;
if ( V_10 == V_16 ) {
if ( V_16 != F_3 ( V_16 ) )
V_4 = 1 ;
} else if ( V_10 == F_3 ( V_16 ) ) {
} else {
return F_5 ( - V_17 ) ;
}
V_10 = F_1 ( V_2 , V_7 + 4 , V_4 ) ;
V_13 = F_6 ( * ( V_18 * ) & V_10 ) ;
V_14 = F_7 ( sizeof( * V_14 ) , V_19 ) ;
if ( ! V_14 )
return F_5 ( - V_20 ) ;
V_14 -> V_21 = F_7 ( sizeof( V_14 -> V_21 [ 0 ] ) * V_13 , V_19 ) ;
V_14 -> V_22 = F_7 ( sizeof( V_14 -> V_22 [ 0 ] ) * V_13 , V_19 ) ;
if ( ! V_14 -> V_21 || ! V_14 -> V_22 ) {
F_8 ( V_14 -> V_21 ) ;
F_8 ( V_14 -> V_22 ) ;
F_8 ( V_14 ) ;
return F_5 ( - V_20 ) ;
}
V_14 -> V_23 = V_13 ;
V_14 -> V_9 = V_9 ;
V_14 -> V_2 = V_2 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
union V_24 * V_25 ;
for ( V_12 = 0 ; V_12 < sizeof( V_14 -> V_21 [ 0 ] ) ; V_12 += 4 ) {
* ( T_1 * ) ( ( void * ) ( V_14 -> V_21 + V_11 ) + V_12 ) =
F_1 ( V_2 , V_7 + ( V_11 * 64 ) + V_12 , V_4 ) ;
}
V_25 = & V_14 -> V_21 [ V_11 ] ;
V_14 -> V_22 [ V_11 ] = F_5 ( - V_26 ) ;
if ( V_25 -> V_27 . V_28 == V_29 ) {
struct V_30 * V_31 = & V_25 -> V_32 . V_30 ;
T_2 V_33 = F_9 ( V_25 -> V_32 . V_34 ) ;
T_2 V_35 = F_9 ( V_31 -> V_36 ) ;
V_33 += V_8 ;
V_35 += V_8 ;
V_15 = F_4 ( V_2 , V_33 , V_35 ,
V_9 + 1 ) ;
V_14 -> V_22 [ V_11 ] = V_15 ;
if ( F_10 ( V_15 ) )
continue;
V_15 -> V_37 = V_14 ;
V_15 -> V_38 = V_35 ;
}
}
return V_14 ;
}
int F_11 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_6 * V_39 ;
if ( V_2 -> V_40 )
return - V_41 ;
V_39 = F_4 ( V_2 , V_3 , 0 , 0 ) ;
if ( F_10 ( V_39 ) )
return F_12 ( V_39 ) ;
V_2 -> V_40 = V_39 ;
return 0 ;
}
static void F_13 ( struct V_6 * V_14 )
{
int V_11 , V_13 ;
if ( ! V_14 )
return;
V_13 = V_14 -> V_23 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
if ( F_10 ( V_14 -> V_22 [ V_11 ] ) )
continue;
F_13 ( V_14 -> V_22 [ V_11 ] ) ;
}
F_8 ( V_14 -> V_21 ) ;
F_8 ( V_14 -> V_22 ) ;
F_8 ( V_14 ) ;
}
int F_14 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_40 ) ;
V_2 -> V_40 = NULL ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , struct V_42 * V_43 , char * V_44 ,
int V_45 )
{
int V_39 ;
V_39 = V_2 -> V_46 -> V_47 ( V_2 , V_43 , V_44 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_45 < 0 )
return V_39 ;
V_39 = F_11 ( V_2 , V_45 ) ;
if ( V_39 < 0 ) {
F_16 ( & V_2 -> V_48 , L_1 ,
V_45 ) ;
return - V_26 ;
}
F_17 ( V_2 ) ;
return 0 ;
}
static void F_18 ( const struct V_1 * V_2 ,
const struct V_6 * V_14 )
{
int V_11 , V_12 , V_13 = V_14 -> V_23 , V_9 = V_14 -> V_9 ;
const struct V_6 * V_49 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
unsigned long V_50 ;
union V_24 * V_25 ;
struct V_51 * V_52 ;
struct V_30 * V_31 ;
V_25 = & V_14 -> V_21 [ V_11 ] ;
V_31 = & V_25 -> V_48 . V_30 ;
V_52 = & V_31 -> V_53 ;
V_50 = 0 ;
for ( V_49 = V_14 ; V_49 ; V_49 = V_49 -> V_37 )
V_50 += V_49 -> V_38 ;
F_19 ( & V_2 -> V_48 , L_2 ) ;
for ( V_12 = 0 ; V_12 < V_9 ; V_12 ++ )
F_20 ( V_54 L_3 ) ;
switch ( V_25 -> V_27 . V_28 ) {
case V_55 :
F_20 ( V_54 L_4 ,
F_9 ( V_52 -> V_56 ) ,
F_3 ( V_52 -> V_57 ) ,
V_52 -> V_58 ) ;
break;
case V_59 :
F_20 ( V_54 L_5 ,
F_9 ( V_52 -> V_56 ) ,
F_3 ( V_52 -> V_57 ) ,
V_52 -> V_58 ,
F_9 ( V_31 -> V_36 ) + V_50 ,
F_9 ( V_31 -> V_60 ) + V_50 ) ;
break;
case V_29 :
F_20 ( V_54 L_6 ,
F_9 ( V_52 -> V_56 ) ,
F_3 ( V_52 -> V_57 ) ,
V_52 -> V_58 ,
F_9 ( V_31 -> V_36 ) + V_50 ) ;
if ( F_10 ( V_14 -> V_22 [ V_11 ] ) ) {
F_20 ( V_54 L_7 ,
F_12 ( V_14 -> V_22 [ V_11 ] ) ) ;
break;
}
F_18 ( V_2 , V_14 -> V_22 [ V_11 ] ) ;
break;
case V_61 :
F_20 ( V_54 L_8 ) ;
break;
case V_62 :
F_20 ( V_54 L_9 ) ;
break;
case V_63 :
F_20 ( V_54 L_10 ) ;
break;
case V_64 :
F_20 ( V_54 L_11 ) ;
break;
default:
F_20 ( V_54 L_12 ,
V_25 -> V_27 . V_28 ) ;
break;
}
}
}
void F_21 ( const struct V_1 * V_2 )
{
if ( ! V_2 -> V_40 )
return;
F_18 ( V_2 , V_2 -> V_40 ) ;
}
signed long F_22 ( struct V_6 * V_65 ,
T_2 V_66 , T_1 V_67 , unsigned long * V_68 )
{
signed long V_5 = - V_26 ;
union V_24 * V_25 ;
struct V_51 * V_52 ;
struct V_30 * V_31 ;
int V_11 , V_13 = V_65 -> V_23 ;
T_2 V_69 , V_70 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
V_25 = & V_65 -> V_21 [ V_11 ] ;
V_31 = & V_25 -> V_48 . V_30 ;
V_52 = & V_31 -> V_53 ;
if ( ! F_10 ( V_65 -> V_22 [ V_11 ] ) )
V_5 = F_22 ( V_65 -> V_22 [ V_11 ] ,
V_66 , V_67 , V_68 ) ;
if ( V_5 >= 0 )
return V_5 + V_65 -> V_38 ;
if ( V_25 -> V_27 . V_28 != V_59 )
continue;
if ( F_9 ( V_52 -> V_56 ) != V_66 )
continue;
if ( F_3 ( V_52 -> V_57 ) != V_67 )
continue;
V_69 = F_9 ( V_31 -> V_60 ) ;
V_70 = F_9 ( V_31 -> V_36 ) ;
if ( V_68 )
* V_68 = ( F_23 ( * V_68 ) ) ( V_69 + 1 - V_70 ) ;
return V_70 + V_65 -> V_38 ;
}
return V_5 ;
}
