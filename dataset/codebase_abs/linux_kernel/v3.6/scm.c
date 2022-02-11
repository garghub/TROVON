static T_1 int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_3 = F_2 () ;
if ( ( V_2 -> V_4 == F_3 ( V_5 ) || F_4 ( V_6 ) ) &&
( ( V_2 -> V_7 == V_3 -> V_7 || V_2 -> V_7 == V_3 -> V_8 ||
V_2 -> V_7 == V_3 -> V_9 ) || F_4 ( V_10 ) ) &&
( ( V_2 -> V_11 == V_3 -> V_11 || V_2 -> V_11 == V_3 -> V_12 ||
V_2 -> V_11 == V_3 -> V_13 ) || F_4 ( V_14 ) ) ) {
return 0 ;
}
return - V_15 ;
}
static int F_5 ( struct V_16 * V_17 , struct V_18 * * V_19 )
{
int * V_20 = ( int * ) F_6 ( V_17 ) ;
struct V_18 * V_21 = * V_19 ;
struct V_22 * * V_23 ;
int V_24 , V_25 ;
V_25 = ( V_17 -> V_26 - F_7 ( sizeof( struct V_16 ) ) ) / sizeof( int ) ;
if ( V_25 <= 0 )
return 0 ;
if ( V_25 > V_27 )
return - V_28 ;
if ( ! V_21 )
{
V_21 = F_8 ( sizeof( struct V_18 ) , V_29 ) ;
if ( ! V_21 )
return - V_30 ;
* V_19 = V_21 ;
V_21 -> V_31 = 0 ;
V_21 -> V_32 = V_27 ;
}
V_23 = & V_21 -> V_33 [ V_21 -> V_31 ] ;
if ( V_21 -> V_31 + V_25 > V_21 -> V_32 )
return - V_28 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ )
{
int V_34 = V_20 [ V_24 ] ;
struct V_22 * V_22 ;
if ( V_34 < 0 || ! ( V_22 = F_9 ( V_34 ) ) )
return - V_35 ;
* V_23 ++ = V_22 ;
V_21 -> V_31 ++ ;
}
return V_25 ;
}
void F_10 ( struct V_36 * V_37 )
{
struct V_18 * V_21 = V_37 -> V_33 ;
int V_24 ;
if ( V_21 ) {
V_37 -> V_33 = NULL ;
for ( V_24 = V_21 -> V_31 - 1 ; V_24 >= 0 ; V_24 -- )
F_11 ( V_21 -> V_33 [ V_24 ] ) ;
F_12 ( V_21 ) ;
}
}
int F_13 ( struct V_38 * V_39 , struct V_40 * V_41 , struct V_36 * V_42 )
{
struct V_16 * V_17 ;
int V_43 ;
for ( V_17 = F_14 ( V_41 ) ; V_17 ; V_17 = F_15 ( V_41 , V_17 ) )
{
V_43 = - V_28 ;
if ( ! F_16 ( V_41 , V_17 ) )
goto error;
if ( V_17 -> V_44 != V_45 )
continue;
switch ( V_17 -> V_46 )
{
case V_47 :
if ( ! V_39 -> V_48 || V_39 -> V_48 -> V_49 != V_50 )
goto error;
V_43 = F_5 ( V_17 , & V_42 -> V_33 ) ;
if ( V_43 < 0 )
goto error;
break;
case V_51 :
if ( V_17 -> V_26 != F_17 ( sizeof( struct V_1 ) ) )
goto error;
memcpy ( & V_42 -> V_2 , F_6 ( V_17 ) , sizeof( struct V_1 ) ) ;
V_43 = F_1 ( & V_42 -> V_2 ) ;
if ( V_43 )
goto error;
if ( ! V_42 -> V_4 || F_18 ( V_42 -> V_4 ) != V_42 -> V_2 . V_4 ) {
struct V_4 * V_4 ;
V_43 = - V_52 ;
V_4 = F_19 ( V_42 -> V_2 . V_4 ) ;
if ( ! V_4 )
goto error;
F_20 ( V_42 -> V_4 ) ;
V_42 -> V_4 = V_4 ;
}
if ( ! V_42 -> V_3 ||
( V_42 -> V_3 -> V_8 != V_42 -> V_2 . V_7 ) ||
( V_42 -> V_3 -> V_12 != V_42 -> V_2 . V_11 ) ) {
struct V_3 * V_3 ;
V_43 = - V_30 ;
V_3 = F_21 () ;
if ( ! V_3 )
goto error;
V_3 -> V_7 = V_3 -> V_8 = V_42 -> V_2 . V_7 ;
V_3 -> V_11 = V_3 -> V_12 = V_42 -> V_2 . V_11 ;
if ( V_42 -> V_3 )
F_22 ( V_42 -> V_3 ) ;
V_42 -> V_3 = V_3 ;
}
break;
default:
goto error;
}
}
if ( V_42 -> V_33 && ! V_42 -> V_33 -> V_31 )
{
F_12 ( V_42 -> V_33 ) ;
V_42 -> V_33 = NULL ;
}
return 0 ;
error:
F_23 ( V_42 ) ;
return V_43 ;
}
int F_24 ( struct V_40 * V_41 , int V_53 , int type , int V_54 , void * V_55 )
{
struct V_16 T_2 * V_56
= ( V_57 struct V_16 T_2 * ) V_41 -> V_58 ;
struct V_16 V_59 ;
int V_60 = F_17 ( V_54 ) ;
int V_43 ;
if ( V_61 & V_41 -> V_62 )
return F_25 ( V_41 , V_53 , type , V_54 , V_55 ) ;
if ( V_56 == NULL || V_41 -> V_63 < sizeof( * V_56 ) ) {
V_41 -> V_62 |= V_64 ;
return 0 ;
}
if ( V_41 -> V_63 < V_60 ) {
V_41 -> V_62 |= V_64 ;
V_60 = V_41 -> V_63 ;
}
V_59 . V_44 = V_53 ;
V_59 . V_46 = type ;
V_59 . V_26 = V_60 ;
V_43 = - V_65 ;
if ( F_26 ( V_56 , & V_59 , sizeof V_59 ) )
goto V_66;
if ( F_26 ( F_6 ( V_56 ) , V_55 , V_60 - sizeof( struct V_16 ) ) )
goto V_66;
V_60 = F_27 ( V_54 ) ;
if ( V_41 -> V_63 < V_60 )
V_60 = V_41 -> V_63 ;
V_41 -> V_58 += V_60 ;
V_41 -> V_63 -= V_60 ;
V_43 = 0 ;
V_66:
return V_43 ;
}
void F_28 ( struct V_40 * V_41 , struct V_36 * V_37 )
{
struct V_16 T_2 * V_56
= ( V_57 struct V_16 T_2 * ) V_41 -> V_58 ;
int V_67 = 0 ;
int V_68 = V_37 -> V_33 -> V_31 ;
struct V_22 * * V_33 = V_37 -> V_33 -> V_33 ;
int T_2 * V_69 ;
int V_43 = 0 , V_24 ;
if ( V_61 & V_41 -> V_62 ) {
F_29 ( V_41 , V_37 ) ;
return;
}
if ( V_41 -> V_63 > sizeof( struct V_16 ) )
V_67 = ( ( V_41 -> V_63 - sizeof( struct V_16 ) )
/ sizeof( int ) ) ;
if ( V_68 < V_67 )
V_67 = V_68 ;
for ( V_24 = 0 , V_69 = ( V_57 int T_2 * ) F_6 ( V_56 ) ; V_24 < V_67 ;
V_24 ++ , V_69 ++ )
{
struct V_38 * V_39 ;
int V_70 ;
V_43 = F_30 ( V_33 [ V_24 ] ) ;
if ( V_43 )
break;
V_43 = F_31 ( V_71 & V_41 -> V_62
? V_72 : 0 ) ;
if ( V_43 < 0 )
break;
V_70 = V_43 ;
V_43 = F_32 ( V_70 , V_69 ) ;
if ( V_43 ) {
F_33 ( V_70 ) ;
break;
}
F_34 ( V_33 [ V_24 ] ) ;
V_39 = F_35 ( V_33 [ V_24 ] , & V_43 ) ;
if ( V_39 )
F_36 ( V_39 -> V_73 , V_5 ) ;
F_37 ( V_70 , V_33 [ V_24 ] ) ;
}
if ( V_24 > 0 )
{
int V_60 = F_17 ( V_24 * sizeof( int ) ) ;
V_43 = F_32 ( V_45 , & V_56 -> V_44 ) ;
if ( ! V_43 )
V_43 = F_32 ( V_47 , & V_56 -> V_46 ) ;
if ( ! V_43 )
V_43 = F_32 ( V_60 , & V_56 -> V_26 ) ;
if ( ! V_43 ) {
V_60 = F_27 ( V_24 * sizeof( int ) ) ;
V_41 -> V_58 += V_60 ;
V_41 -> V_63 -= V_60 ;
}
}
if ( V_24 < V_68 || ( V_68 && V_67 <= 0 ) )
V_41 -> V_62 |= V_64 ;
F_10 ( V_37 ) ;
}
struct V_18 * F_38 ( struct V_18 * V_21 )
{
struct V_18 * V_74 ;
int V_24 ;
if ( ! V_21 )
return NULL ;
V_74 = F_39 ( V_21 , F_40 ( struct V_18 , V_33 [ V_21 -> V_31 ] ) ,
V_29 ) ;
if ( V_74 ) {
for ( V_24 = 0 ; V_24 < V_21 -> V_31 ; V_24 ++ )
F_34 ( V_21 -> V_33 [ V_24 ] ) ;
V_74 -> V_32 = V_74 -> V_31 ;
}
return V_74 ;
}
