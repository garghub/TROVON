static T_1 int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_3 = F_2 () ;
T_2 V_4 = F_3 ( V_3 -> V_5 , V_2 -> V_4 ) ;
T_3 V_6 = F_4 ( V_3 -> V_5 , V_2 -> V_6 ) ;
if ( ! F_5 ( V_4 ) || ! F_6 ( V_6 ) )
return - V_7 ;
if ( ( V_2 -> V_8 == F_7 ( V_9 ) || F_8 ( V_10 ) ) &&
( ( F_9 ( V_4 , V_3 -> V_4 ) || F_9 ( V_4 , V_3 -> V_11 ) ||
F_9 ( V_4 , V_3 -> V_12 ) ) || F_8 ( V_13 ) ) &&
( ( F_10 ( V_6 , V_3 -> V_6 ) || F_10 ( V_6 , V_3 -> V_14 ) ||
F_10 ( V_6 , V_3 -> V_15 ) ) || F_8 ( V_16 ) ) ) {
return 0 ;
}
return - V_17 ;
}
static int F_11 ( struct V_18 * V_19 , struct V_20 * * V_21 )
{
int * V_22 = ( int * ) F_12 ( V_19 ) ;
struct V_20 * V_23 = * V_21 ;
struct V_24 * * V_25 ;
int V_26 , V_27 ;
V_27 = ( V_19 -> V_28 - F_13 ( sizeof( struct V_18 ) ) ) / sizeof( int ) ;
if ( V_27 <= 0 )
return 0 ;
if ( V_27 > V_29 )
return - V_7 ;
if ( ! V_23 )
{
V_23 = F_14 ( sizeof( struct V_20 ) , V_30 ) ;
if ( ! V_23 )
return - V_31 ;
* V_21 = V_23 ;
V_23 -> V_32 = 0 ;
V_23 -> V_33 = V_29 ;
}
V_25 = & V_23 -> V_34 [ V_23 -> V_32 ] ;
if ( V_23 -> V_32 + V_27 > V_23 -> V_33 )
return - V_7 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ )
{
int V_35 = V_22 [ V_26 ] ;
struct V_24 * V_24 ;
if ( V_35 < 0 || ! ( V_24 = F_15 ( V_35 ) ) )
return - V_36 ;
* V_25 ++ = V_24 ;
V_23 -> V_32 ++ ;
}
return V_27 ;
}
void F_16 ( struct V_37 * V_38 )
{
struct V_20 * V_23 = V_38 -> V_34 ;
int V_26 ;
if ( V_23 ) {
V_38 -> V_34 = NULL ;
for ( V_26 = V_23 -> V_32 - 1 ; V_26 >= 0 ; V_26 -- )
F_17 ( V_23 -> V_34 [ V_26 ] ) ;
F_18 ( V_23 ) ;
}
}
int F_19 ( struct V_39 * V_40 , struct V_41 * V_42 , struct V_37 * V_43 )
{
struct V_18 * V_19 ;
int V_44 ;
for ( V_19 = F_20 ( V_42 ) ; V_19 ; V_19 = F_21 ( V_42 , V_19 ) )
{
V_44 = - V_7 ;
if ( ! F_22 ( V_42 , V_19 ) )
goto error;
if ( V_19 -> V_45 != V_46 )
continue;
switch ( V_19 -> V_47 )
{
case V_48 :
if ( ! V_40 -> V_49 || V_40 -> V_49 -> V_50 != V_51 )
goto error;
V_44 = F_11 ( V_19 , & V_43 -> V_34 ) ;
if ( V_44 < 0 )
goto error;
break;
case V_52 :
{
struct V_1 V_2 ;
T_2 V_4 ;
T_3 V_6 ;
if ( V_19 -> V_28 != F_23 ( sizeof( struct V_1 ) ) )
goto error;
memcpy ( & V_2 , F_12 ( V_19 ) , sizeof( struct V_1 ) ) ;
V_44 = F_1 ( & V_2 ) ;
if ( V_44 )
goto error;
V_43 -> V_2 . V_8 = V_2 . V_8 ;
if ( ! V_43 -> V_8 || F_24 ( V_43 -> V_8 ) != V_2 . V_8 ) {
struct V_8 * V_8 ;
V_44 = - V_53 ;
V_8 = F_25 ( V_2 . V_8 ) ;
if ( ! V_8 )
goto error;
F_26 ( V_43 -> V_8 ) ;
V_43 -> V_8 = V_8 ;
}
V_44 = - V_7 ;
V_4 = F_3 ( F_27 () , V_2 . V_4 ) ;
V_6 = F_4 ( F_27 () , V_2 . V_6 ) ;
if ( ! F_5 ( V_4 ) || ! F_6 ( V_6 ) )
goto error;
V_43 -> V_2 . V_4 = V_4 ;
V_43 -> V_2 . V_6 = V_6 ;
if ( ! V_43 -> V_3 ||
! F_9 ( V_43 -> V_3 -> V_11 , V_4 ) ||
! F_10 ( V_43 -> V_3 -> V_14 , V_6 ) ) {
struct V_3 * V_3 ;
V_44 = - V_31 ;
V_3 = F_28 () ;
if ( ! V_3 )
goto error;
V_3 -> V_4 = V_3 -> V_11 = V_4 ;
V_3 -> V_6 = V_3 -> V_14 = V_6 ;
if ( V_43 -> V_3 )
F_29 ( V_43 -> V_3 ) ;
V_43 -> V_3 = V_3 ;
}
break;
}
default:
goto error;
}
}
if ( V_43 -> V_34 && ! V_43 -> V_34 -> V_32 )
{
F_18 ( V_43 -> V_34 ) ;
V_43 -> V_34 = NULL ;
}
return 0 ;
error:
F_30 ( V_43 ) ;
return V_44 ;
}
int F_31 ( struct V_41 * V_42 , int V_54 , int type , int V_55 , void * V_56 )
{
struct V_18 T_4 * V_57
= ( V_58 struct V_18 T_4 * ) V_42 -> V_59 ;
struct V_18 V_60 ;
int V_61 = F_23 ( V_55 ) ;
int V_44 ;
if ( V_62 & V_42 -> V_63 )
return F_32 ( V_42 , V_54 , type , V_55 , V_56 ) ;
if ( V_57 == NULL || V_42 -> V_64 < sizeof( * V_57 ) ) {
V_42 -> V_63 |= V_65 ;
return 0 ;
}
if ( V_42 -> V_64 < V_61 ) {
V_42 -> V_63 |= V_65 ;
V_61 = V_42 -> V_64 ;
}
V_60 . V_45 = V_54 ;
V_60 . V_47 = type ;
V_60 . V_28 = V_61 ;
V_44 = - V_66 ;
if ( F_33 ( V_57 , & V_60 , sizeof V_60 ) )
goto V_67;
if ( F_33 ( F_12 ( V_57 ) , V_56 , V_61 - sizeof( struct V_18 ) ) )
goto V_67;
V_61 = F_34 ( V_55 ) ;
if ( V_42 -> V_64 < V_61 )
V_61 = V_42 -> V_64 ;
V_42 -> V_59 += V_61 ;
V_42 -> V_64 -= V_61 ;
V_44 = 0 ;
V_67:
return V_44 ;
}
void F_35 ( struct V_41 * V_42 , struct V_37 * V_38 )
{
struct V_18 T_4 * V_57
= ( V_58 struct V_18 T_4 * ) V_42 -> V_59 ;
int V_68 = 0 ;
int V_69 = V_38 -> V_34 -> V_32 ;
struct V_24 * * V_34 = V_38 -> V_34 -> V_34 ;
int T_4 * V_70 ;
int V_44 = 0 , V_26 ;
if ( V_62 & V_42 -> V_63 ) {
F_36 ( V_42 , V_38 ) ;
return;
}
if ( V_42 -> V_64 > sizeof( struct V_18 ) )
V_68 = ( ( V_42 -> V_64 - sizeof( struct V_18 ) )
/ sizeof( int ) ) ;
if ( V_69 < V_68 )
V_68 = V_69 ;
for ( V_26 = 0 , V_70 = ( V_58 int T_4 * ) F_12 ( V_57 ) ; V_26 < V_68 ;
V_26 ++ , V_70 ++ )
{
struct V_39 * V_40 ;
int V_71 ;
V_44 = F_37 ( V_34 [ V_26 ] ) ;
if ( V_44 )
break;
V_44 = F_38 ( V_72 & V_42 -> V_63
? V_73 : 0 ) ;
if ( V_44 < 0 )
break;
V_71 = V_44 ;
V_44 = F_39 ( V_71 , V_70 ) ;
if ( V_44 ) {
F_40 ( V_71 ) ;
break;
}
V_40 = F_41 ( V_34 [ V_26 ] , & V_44 ) ;
if ( V_40 )
F_42 ( V_40 -> V_74 , V_9 ) ;
F_43 ( V_71 , F_44 ( V_34 [ V_26 ] ) ) ;
}
if ( V_26 > 0 )
{
int V_61 = F_23 ( V_26 * sizeof( int ) ) ;
V_44 = F_39 ( V_46 , & V_57 -> V_45 ) ;
if ( ! V_44 )
V_44 = F_39 ( V_48 , & V_57 -> V_47 ) ;
if ( ! V_44 )
V_44 = F_39 ( V_61 , & V_57 -> V_28 ) ;
if ( ! V_44 ) {
V_61 = F_34 ( V_26 * sizeof( int ) ) ;
V_42 -> V_59 += V_61 ;
V_42 -> V_64 -= V_61 ;
}
}
if ( V_26 < V_69 || ( V_69 && V_68 <= 0 ) )
V_42 -> V_63 |= V_65 ;
F_16 ( V_38 ) ;
}
struct V_20 * F_45 ( struct V_20 * V_23 )
{
struct V_20 * V_75 ;
int V_26 ;
if ( ! V_23 )
return NULL ;
V_75 = F_46 ( V_23 , F_47 ( struct V_20 , V_34 [ V_23 -> V_32 ] ) ,
V_30 ) ;
if ( V_75 ) {
for ( V_26 = 0 ; V_26 < V_23 -> V_32 ; V_26 ++ )
F_44 ( V_23 -> V_34 [ V_26 ] ) ;
V_75 -> V_33 = V_75 -> V_32 ;
}
return V_75 ;
}
