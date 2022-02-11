static T_1 int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_3 = F_2 () ;
T_2 V_4 = F_3 ( V_3 -> V_5 , V_2 -> V_4 ) ;
T_3 V_6 = F_4 ( V_3 -> V_5 , V_2 -> V_6 ) ;
if ( ! F_5 ( V_4 ) || ! F_6 ( V_6 ) )
return - V_7 ;
if ( ( V_2 -> V_8 == F_7 ( V_9 ) ||
F_8 ( V_9 -> V_10 -> V_11 -> V_5 , V_12 ) ) &&
( ( F_9 ( V_4 , V_3 -> V_4 ) || F_9 ( V_4 , V_3 -> V_13 ) ||
F_9 ( V_4 , V_3 -> V_14 ) ) || F_10 ( V_15 ) ) &&
( ( F_11 ( V_6 , V_3 -> V_6 ) || F_11 ( V_6 , V_3 -> V_16 ) ||
F_11 ( V_6 , V_3 -> V_17 ) ) || F_10 ( V_18 ) ) ) {
return 0 ;
}
return - V_19 ;
}
static int F_12 ( struct V_20 * V_21 , struct V_22 * * V_23 )
{
int * V_24 = ( int * ) F_13 ( V_21 ) ;
struct V_22 * V_25 = * V_23 ;
struct V_26 * * V_27 ;
int V_28 , V_29 ;
V_29 = ( V_21 -> V_30 - F_14 ( sizeof( struct V_20 ) ) ) / sizeof( int ) ;
if ( V_29 <= 0 )
return 0 ;
if ( V_29 > V_31 )
return - V_7 ;
if ( ! V_25 )
{
V_25 = F_15 ( sizeof( struct V_22 ) , V_32 ) ;
if ( ! V_25 )
return - V_33 ;
* V_23 = V_25 ;
V_25 -> V_34 = 0 ;
V_25 -> V_35 = V_31 ;
}
V_27 = & V_25 -> V_36 [ V_25 -> V_34 ] ;
if ( V_25 -> V_34 + V_29 > V_25 -> V_35 )
return - V_7 ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ )
{
int V_37 = V_24 [ V_28 ] ;
struct V_26 * V_26 ;
if ( V_37 < 0 || ! ( V_26 = F_16 ( V_37 ) ) )
return - V_38 ;
* V_27 ++ = V_26 ;
V_25 -> V_34 ++ ;
}
return V_29 ;
}
void F_17 ( struct V_39 * V_40 )
{
struct V_22 * V_25 = V_40 -> V_36 ;
int V_28 ;
if ( V_25 ) {
V_40 -> V_36 = NULL ;
for ( V_28 = V_25 -> V_34 - 1 ; V_28 >= 0 ; V_28 -- )
F_18 ( V_25 -> V_36 [ V_28 ] ) ;
F_19 ( V_25 ) ;
}
}
int F_20 ( struct V_41 * V_42 , struct V_43 * V_44 , struct V_39 * V_45 )
{
struct V_20 * V_21 ;
int V_46 ;
for ( V_21 = F_21 ( V_44 ) ; V_21 ; V_21 = F_22 ( V_44 , V_21 ) )
{
V_46 = - V_7 ;
if ( ! F_23 ( V_44 , V_21 ) )
goto error;
if ( V_21 -> V_47 != V_48 )
continue;
switch ( V_21 -> V_49 )
{
case V_50 :
if ( ! V_42 -> V_51 || V_42 -> V_51 -> V_52 != V_53 )
goto error;
V_46 = F_12 ( V_21 , & V_45 -> V_36 ) ;
if ( V_46 < 0 )
goto error;
break;
case V_54 :
{
struct V_1 V_2 ;
T_2 V_4 ;
T_3 V_6 ;
if ( V_21 -> V_30 != F_24 ( sizeof( struct V_1 ) ) )
goto error;
memcpy ( & V_2 , F_13 ( V_21 ) , sizeof( struct V_1 ) ) ;
V_46 = F_1 ( & V_2 ) ;
if ( V_46 )
goto error;
V_45 -> V_2 . V_8 = V_2 . V_8 ;
if ( ! V_45 -> V_8 || F_25 ( V_45 -> V_8 ) != V_2 . V_8 ) {
struct V_8 * V_8 ;
V_46 = - V_55 ;
V_8 = F_26 ( V_2 . V_8 ) ;
if ( ! V_8 )
goto error;
F_27 ( V_45 -> V_8 ) ;
V_45 -> V_8 = V_8 ;
}
V_46 = - V_7 ;
V_4 = F_3 ( F_28 () , V_2 . V_4 ) ;
V_6 = F_4 ( F_28 () , V_2 . V_6 ) ;
if ( ! F_5 ( V_4 ) || ! F_6 ( V_6 ) )
goto error;
V_45 -> V_2 . V_4 = V_4 ;
V_45 -> V_2 . V_6 = V_6 ;
if ( ! V_45 -> V_3 ||
! F_9 ( V_45 -> V_3 -> V_13 , V_4 ) ||
! F_11 ( V_45 -> V_3 -> V_16 , V_6 ) ) {
struct V_3 * V_3 ;
V_46 = - V_33 ;
V_3 = F_29 () ;
if ( ! V_3 )
goto error;
V_3 -> V_4 = V_3 -> V_13 = V_4 ;
V_3 -> V_6 = V_3 -> V_16 = V_6 ;
if ( V_45 -> V_3 )
F_30 ( V_45 -> V_3 ) ;
V_45 -> V_3 = V_3 ;
}
break;
}
default:
goto error;
}
}
if ( V_45 -> V_36 && ! V_45 -> V_36 -> V_34 )
{
F_19 ( V_45 -> V_36 ) ;
V_45 -> V_36 = NULL ;
}
return 0 ;
error:
F_31 ( V_45 ) ;
return V_46 ;
}
int F_32 ( struct V_43 * V_44 , int V_56 , int type , int V_57 , void * V_58 )
{
struct V_20 T_4 * V_59
= ( V_60 struct V_20 T_4 * ) V_44 -> V_61 ;
struct V_20 V_62 ;
int V_63 = F_24 ( V_57 ) ;
int V_46 ;
if ( V_64 & V_44 -> V_65 )
return F_33 ( V_44 , V_56 , type , V_57 , V_58 ) ;
if ( V_59 == NULL || V_44 -> V_66 < sizeof( * V_59 ) ) {
V_44 -> V_65 |= V_67 ;
return 0 ;
}
if ( V_44 -> V_66 < V_63 ) {
V_44 -> V_65 |= V_67 ;
V_63 = V_44 -> V_66 ;
}
V_62 . V_47 = V_56 ;
V_62 . V_49 = type ;
V_62 . V_30 = V_63 ;
V_46 = - V_68 ;
if ( F_34 ( V_59 , & V_62 , sizeof V_62 ) )
goto V_69;
if ( F_34 ( F_13 ( V_59 ) , V_58 , V_63 - sizeof( struct V_20 ) ) )
goto V_69;
V_63 = F_35 ( V_57 ) ;
if ( V_44 -> V_66 < V_63 )
V_63 = V_44 -> V_66 ;
V_44 -> V_61 += V_63 ;
V_44 -> V_66 -= V_63 ;
V_46 = 0 ;
V_69:
return V_46 ;
}
void F_36 ( struct V_43 * V_44 , struct V_39 * V_40 )
{
struct V_20 T_4 * V_59
= ( V_60 struct V_20 T_4 * ) V_44 -> V_61 ;
int V_70 = 0 ;
int V_71 = V_40 -> V_36 -> V_34 ;
struct V_26 * * V_36 = V_40 -> V_36 -> V_36 ;
int T_4 * V_72 ;
int V_46 = 0 , V_28 ;
if ( V_64 & V_44 -> V_65 ) {
F_37 ( V_44 , V_40 ) ;
return;
}
if ( V_44 -> V_66 > sizeof( struct V_20 ) )
V_70 = ( ( V_44 -> V_66 - sizeof( struct V_20 ) )
/ sizeof( int ) ) ;
if ( V_71 < V_70 )
V_70 = V_71 ;
for ( V_28 = 0 , V_72 = ( V_60 int T_4 * ) F_13 ( V_59 ) ; V_28 < V_70 ;
V_28 ++ , V_72 ++ )
{
struct V_41 * V_42 ;
int V_73 ;
V_46 = F_38 ( V_36 [ V_28 ] ) ;
if ( V_46 )
break;
V_46 = F_39 ( V_74 & V_44 -> V_65
? V_75 : 0 ) ;
if ( V_46 < 0 )
break;
V_73 = V_46 ;
V_46 = F_40 ( V_73 , V_72 ) ;
if ( V_46 ) {
F_41 ( V_73 ) ;
break;
}
V_42 = F_42 ( V_36 [ V_28 ] , & V_46 ) ;
if ( V_42 ) {
F_43 ( V_42 -> V_76 , V_9 ) ;
F_44 ( V_42 -> V_76 , V_9 ) ;
}
F_45 ( V_73 , F_46 ( V_36 [ V_28 ] ) ) ;
}
if ( V_28 > 0 )
{
int V_63 = F_24 ( V_28 * sizeof( int ) ) ;
V_46 = F_40 ( V_48 , & V_59 -> V_47 ) ;
if ( ! V_46 )
V_46 = F_40 ( V_50 , & V_59 -> V_49 ) ;
if ( ! V_46 )
V_46 = F_40 ( V_63 , & V_59 -> V_30 ) ;
if ( ! V_46 ) {
V_63 = F_35 ( V_28 * sizeof( int ) ) ;
V_44 -> V_61 += V_63 ;
V_44 -> V_66 -= V_63 ;
}
}
if ( V_28 < V_71 || ( V_71 && V_70 <= 0 ) )
V_44 -> V_65 |= V_67 ;
F_17 ( V_40 ) ;
}
struct V_22 * F_47 ( struct V_22 * V_25 )
{
struct V_22 * V_77 ;
int V_28 ;
if ( ! V_25 )
return NULL ;
V_77 = F_48 ( V_25 , F_49 ( struct V_22 , V_36 [ V_25 -> V_34 ] ) ,
V_32 ) ;
if ( V_77 ) {
for ( V_28 = 0 ; V_28 < V_25 -> V_34 ; V_28 ++ )
F_46 ( V_25 -> V_36 [ V_28 ] ) ;
V_77 -> V_35 = V_77 -> V_34 ;
}
return V_77 ;
}
