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
if ( V_5 -> V_38 ) {
F_11 ( & V_21 -> V_39 , V_5 -> V_38 ) ;
} else {
F_12 ( V_40 ) ;
V_5 -> V_38 = & V_40 ;
F_13 ( & V_21 -> V_39 , & V_40 ) ;
while ( ! F_14 ( & V_40 ) ) {
V_21 = F_15 ( & V_40 , struct V_18 , V_39 ) ;
F_16 ( & V_21 -> V_39 ) ;
for ( V_24 = V_21 -> V_31 - 1 ; V_24 >= 0 ; V_24 -- )
F_17 ( V_21 -> V_33 [ V_24 ] ) ;
F_18 ( V_21 ) ;
}
V_5 -> V_38 = NULL ;
}
}
}
int F_19 ( struct V_41 * V_42 , struct V_43 * V_44 , struct V_36 * V_45 )
{
struct V_16 * V_17 ;
int V_46 ;
for ( V_17 = F_20 ( V_44 ) ; V_17 ; V_17 = F_21 ( V_44 , V_17 ) )
{
V_46 = - V_28 ;
if ( ! F_22 ( V_44 , V_17 ) )
goto error;
if ( V_17 -> V_47 != V_48 )
continue;
switch ( V_17 -> V_49 )
{
case V_50 :
if ( ! V_42 -> V_51 || V_42 -> V_51 -> V_52 != V_53 )
goto error;
V_46 = F_5 ( V_17 , & V_45 -> V_33 ) ;
if ( V_46 < 0 )
goto error;
break;
case V_54 :
if ( V_17 -> V_26 != F_23 ( sizeof( struct V_1 ) ) )
goto error;
memcpy ( & V_45 -> V_2 , F_6 ( V_17 ) , sizeof( struct V_1 ) ) ;
V_46 = F_1 ( & V_45 -> V_2 ) ;
if ( V_46 )
goto error;
if ( F_24 ( V_45 -> V_4 ) != V_45 -> V_2 . V_4 ) {
struct V_4 * V_4 ;
V_46 = - V_55 ;
V_4 = F_25 ( V_45 -> V_2 . V_4 ) ;
if ( ! V_4 )
goto error;
F_26 ( V_45 -> V_4 ) ;
V_45 -> V_4 = V_4 ;
}
if ( ( V_45 -> V_3 -> V_8 != V_45 -> V_2 . V_7 ) ||
( V_45 -> V_3 -> V_12 != V_45 -> V_2 . V_11 ) ) {
struct V_3 * V_3 ;
V_46 = - V_30 ;
V_3 = F_27 () ;
if ( ! V_3 )
goto error;
V_3 -> V_7 = V_3 -> V_8 = V_45 -> V_2 . V_7 ;
V_3 -> V_11 = V_3 -> V_12 = V_45 -> V_2 . V_11 ;
F_28 ( V_45 -> V_3 ) ;
V_45 -> V_3 = V_3 ;
}
break;
default:
goto error;
}
}
if ( V_45 -> V_33 && ! V_45 -> V_33 -> V_31 )
{
F_18 ( V_45 -> V_33 ) ;
V_45 -> V_33 = NULL ;
}
return 0 ;
error:
F_29 ( V_45 ) ;
return V_46 ;
}
int F_30 ( struct V_43 * V_44 , int V_56 , int type , int V_57 , void * V_58 )
{
struct V_16 T_2 * V_59
= ( V_60 struct V_16 T_2 * ) V_44 -> V_61 ;
struct V_16 V_62 ;
int V_63 = F_23 ( V_57 ) ;
int V_46 ;
if ( V_64 & V_44 -> V_65 )
return F_31 ( V_44 , V_56 , type , V_57 , V_58 ) ;
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
V_62 . V_26 = V_63 ;
V_46 = - V_68 ;
if ( F_32 ( V_59 , & V_62 , sizeof V_62 ) )
goto V_69;
if ( F_32 ( F_6 ( V_59 ) , V_58 , V_63 - sizeof( struct V_16 ) ) )
goto V_69;
V_63 = F_33 ( V_57 ) ;
if ( V_44 -> V_66 < V_63 )
V_63 = V_44 -> V_66 ;
V_44 -> V_61 += V_63 ;
V_44 -> V_66 -= V_63 ;
V_46 = 0 ;
V_69:
return V_46 ;
}
void F_34 ( struct V_43 * V_44 , struct V_36 * V_37 )
{
struct V_16 T_2 * V_59
= ( V_60 struct V_16 T_2 * ) V_44 -> V_61 ;
int V_70 = 0 ;
int V_71 = V_37 -> V_33 -> V_31 ;
struct V_22 * * V_33 = V_37 -> V_33 -> V_33 ;
int T_2 * V_72 ;
int V_46 = 0 , V_24 ;
if ( V_64 & V_44 -> V_65 ) {
F_35 ( V_44 , V_37 ) ;
return;
}
if ( V_44 -> V_66 > sizeof( struct V_16 ) )
V_70 = ( ( V_44 -> V_66 - sizeof( struct V_16 ) )
/ sizeof( int ) ) ;
if ( V_71 < V_70 )
V_70 = V_71 ;
for ( V_24 = 0 , V_72 = ( V_60 int T_2 * ) F_6 ( V_59 ) ; V_24 < V_70 ;
V_24 ++ , V_72 ++ )
{
int V_73 ;
V_46 = F_36 ( V_33 [ V_24 ] ) ;
if ( V_46 )
break;
V_46 = F_37 ( V_74 & V_44 -> V_65
? V_75 : 0 ) ;
if ( V_46 < 0 )
break;
V_73 = V_46 ;
V_46 = F_38 ( V_73 , V_72 ) ;
if ( V_46 ) {
F_39 ( V_73 ) ;
break;
}
F_40 ( V_33 [ V_24 ] ) ;
F_41 ( V_73 , V_33 [ V_24 ] ) ;
}
if ( V_24 > 0 )
{
int V_63 = F_23 ( V_24 * sizeof( int ) ) ;
V_46 = F_38 ( V_48 , & V_59 -> V_47 ) ;
if ( ! V_46 )
V_46 = F_38 ( V_50 , & V_59 -> V_49 ) ;
if ( ! V_46 )
V_46 = F_38 ( V_63 , & V_59 -> V_26 ) ;
if ( ! V_46 ) {
V_63 = F_33 ( V_24 * sizeof( int ) ) ;
V_44 -> V_61 += V_63 ;
V_44 -> V_66 -= V_63 ;
}
}
if ( V_24 < V_71 || ( V_71 && V_70 <= 0 ) )
V_44 -> V_65 |= V_67 ;
F_10 ( V_37 ) ;
}
struct V_18 * F_42 ( struct V_18 * V_21 )
{
struct V_18 * V_76 ;
int V_24 ;
if ( ! V_21 )
return NULL ;
V_76 = F_43 ( V_21 , F_44 ( struct V_18 , V_33 [ V_21 -> V_31 ] ) ,
V_29 ) ;
if ( V_76 ) {
for ( V_24 = 0 ; V_24 < V_21 -> V_31 ; V_24 ++ )
F_40 ( V_21 -> V_33 [ V_24 ] ) ;
V_76 -> V_32 = V_76 -> V_31 ;
}
return V_76 ;
}
