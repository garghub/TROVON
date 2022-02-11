static T_1 int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_3 = F_2 () ;
T_2 V_4 = F_3 ( V_3 -> V_5 , V_2 -> V_4 ) ;
T_3 V_6 = F_4 ( V_3 -> V_5 , V_2 -> V_6 ) ;
if ( ! F_5 ( V_4 ) || ! F_6 ( V_6 ) )
return - V_7 ;
if ( ( V_2 -> V_8 == F_7 ( V_9 ) ||
F_8 ( F_9 ( V_9 ) -> V_5 , V_10 ) ) &&
( ( F_10 ( V_4 , V_3 -> V_4 ) || F_10 ( V_4 , V_3 -> V_11 ) ||
F_10 ( V_4 , V_3 -> V_12 ) ) || F_8 ( V_3 -> V_5 , V_13 ) ) &&
( ( F_11 ( V_6 , V_3 -> V_6 ) || F_11 ( V_6 , V_3 -> V_14 ) ||
F_11 ( V_6 , V_3 -> V_15 ) ) || F_8 ( V_3 -> V_5 , V_16 ) ) ) {
return 0 ;
}
return - V_17 ;
}
static int F_12 ( struct V_18 * V_19 , struct V_20 * * V_21 )
{
int * V_22 = ( int * ) F_13 ( V_19 ) ;
struct V_20 * V_23 = * V_21 ;
struct V_24 * * V_25 ;
int V_26 , V_27 ;
V_27 = ( V_19 -> V_28 - F_14 ( sizeof( struct V_18 ) ) ) / sizeof( int ) ;
if ( V_27 <= 0 )
return 0 ;
if ( V_27 > V_29 )
return - V_7 ;
if ( ! V_23 )
{
V_23 = F_15 ( sizeof( struct V_20 ) , V_30 ) ;
if ( ! V_23 )
return - V_31 ;
* V_21 = V_23 ;
V_23 -> V_32 = 0 ;
V_23 -> V_33 = V_29 ;
V_23 -> V_34 = NULL ;
}
V_25 = & V_23 -> V_35 [ V_23 -> V_32 ] ;
if ( V_23 -> V_32 + V_27 > V_23 -> V_33 )
return - V_7 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ )
{
int V_36 = V_22 [ V_26 ] ;
struct V_24 * V_24 ;
if ( V_36 < 0 || ! ( V_24 = F_16 ( V_36 ) ) )
return - V_37 ;
* V_25 ++ = V_24 ;
V_23 -> V_32 ++ ;
}
if ( ! V_23 -> V_34 )
V_23 -> V_34 = F_17 ( F_18 () ) ;
return V_27 ;
}
void F_19 ( struct V_38 * V_39 )
{
struct V_20 * V_23 = V_39 -> V_35 ;
int V_26 ;
if ( V_23 ) {
V_39 -> V_35 = NULL ;
for ( V_26 = V_23 -> V_32 - 1 ; V_26 >= 0 ; V_26 -- )
F_20 ( V_23 -> V_35 [ V_26 ] ) ;
F_21 ( V_23 -> V_34 ) ;
F_22 ( V_23 ) ;
}
}
int F_23 ( struct V_40 * V_41 , struct V_42 * V_43 , struct V_38 * V_44 )
{
struct V_18 * V_19 ;
int V_45 ;
F_24 (cmsg, msg) {
V_45 = - V_7 ;
if ( ! F_25 ( V_43 , V_19 ) )
goto error;
if ( V_19 -> V_46 != V_47 )
continue;
switch ( V_19 -> V_48 )
{
case V_49 :
if ( ! V_41 -> V_50 || V_41 -> V_50 -> V_51 != V_52 )
goto error;
V_45 = F_12 ( V_19 , & V_44 -> V_35 ) ;
if ( V_45 < 0 )
goto error;
break;
case V_53 :
{
struct V_1 V_2 ;
T_2 V_4 ;
T_3 V_6 ;
if ( V_19 -> V_28 != F_26 ( sizeof( struct V_1 ) ) )
goto error;
memcpy ( & V_2 , F_13 ( V_19 ) , sizeof( struct V_1 ) ) ;
V_45 = F_1 ( & V_2 ) ;
if ( V_45 )
goto error;
V_44 -> V_2 . V_8 = V_2 . V_8 ;
if ( ! V_44 -> V_8 || F_27 ( V_44 -> V_8 ) != V_2 . V_8 ) {
struct V_8 * V_8 ;
V_45 = - V_54 ;
V_8 = F_28 ( V_2 . V_8 ) ;
if ( ! V_8 )
goto error;
F_29 ( V_44 -> V_8 ) ;
V_44 -> V_8 = V_8 ;
}
V_45 = - V_7 ;
V_4 = F_3 ( F_30 () , V_2 . V_4 ) ;
V_6 = F_4 ( F_30 () , V_2 . V_6 ) ;
if ( ! F_5 ( V_4 ) || ! F_6 ( V_6 ) )
goto error;
V_44 -> V_2 . V_4 = V_4 ;
V_44 -> V_2 . V_6 = V_6 ;
break;
}
default:
goto error;
}
}
if ( V_44 -> V_35 && ! V_44 -> V_35 -> V_32 )
{
F_22 ( V_44 -> V_35 ) ;
V_44 -> V_35 = NULL ;
}
return 0 ;
error:
F_31 ( V_44 ) ;
return V_45 ;
}
int F_32 ( struct V_42 * V_43 , int V_55 , int type , int V_56 , void * V_57 )
{
struct V_18 T_4 * V_58
= ( V_59 struct V_18 T_4 * ) V_43 -> V_60 ;
struct V_18 V_61 ;
int V_62 = F_26 ( V_56 ) ;
int V_45 ;
if ( V_63 & V_43 -> V_64 )
return F_33 ( V_43 , V_55 , type , V_56 , V_57 ) ;
if ( V_58 == NULL || V_43 -> V_65 < sizeof( * V_58 ) ) {
V_43 -> V_64 |= V_66 ;
return 0 ;
}
if ( V_43 -> V_65 < V_62 ) {
V_43 -> V_64 |= V_66 ;
V_62 = V_43 -> V_65 ;
}
V_61 . V_46 = V_55 ;
V_61 . V_48 = type ;
V_61 . V_28 = V_62 ;
V_45 = - V_67 ;
if ( F_34 ( V_58 , & V_61 , sizeof V_61 ) )
goto V_68;
if ( F_34 ( F_13 ( V_58 ) , V_57 , V_62 - sizeof( struct V_18 ) ) )
goto V_68;
V_62 = F_35 ( V_56 ) ;
if ( V_43 -> V_65 < V_62 )
V_62 = V_43 -> V_65 ;
V_43 -> V_60 += V_62 ;
V_43 -> V_65 -= V_62 ;
V_45 = 0 ;
V_68:
return V_45 ;
}
void F_36 ( struct V_42 * V_43 , struct V_38 * V_39 )
{
struct V_18 T_4 * V_58
= ( V_59 struct V_18 T_4 * ) V_43 -> V_60 ;
int V_69 = 0 ;
int V_70 = V_39 -> V_35 -> V_32 ;
struct V_24 * * V_35 = V_39 -> V_35 -> V_35 ;
int T_4 * V_71 ;
int V_45 = 0 , V_26 ;
if ( V_63 & V_43 -> V_64 ) {
F_37 ( V_43 , V_39 ) ;
return;
}
if ( V_43 -> V_65 > sizeof( struct V_18 ) )
V_69 = ( ( V_43 -> V_65 - sizeof( struct V_18 ) )
/ sizeof( int ) ) ;
if ( V_70 < V_69 )
V_69 = V_70 ;
for ( V_26 = 0 , V_71 = ( V_59 int T_4 * ) F_13 ( V_58 ) ; V_26 < V_69 ;
V_26 ++ , V_71 ++ )
{
struct V_40 * V_41 ;
int V_72 ;
V_45 = F_38 ( V_35 [ V_26 ] ) ;
if ( V_45 )
break;
V_45 = F_39 ( V_73 & V_43 -> V_64
? V_74 : 0 ) ;
if ( V_45 < 0 )
break;
V_72 = V_45 ;
V_45 = F_40 ( V_72 , V_71 ) ;
if ( V_45 ) {
F_41 ( V_72 ) ;
break;
}
V_41 = F_42 ( V_35 [ V_26 ] , & V_45 ) ;
if ( V_41 ) {
F_43 ( & V_41 -> V_75 -> V_76 ) ;
F_44 ( & V_41 -> V_75 -> V_76 ) ;
}
F_45 ( V_72 , F_46 ( V_35 [ V_26 ] ) ) ;
}
if ( V_26 > 0 )
{
int V_62 = F_26 ( V_26 * sizeof( int ) ) ;
V_45 = F_40 ( V_47 , & V_58 -> V_46 ) ;
if ( ! V_45 )
V_45 = F_40 ( V_49 , & V_58 -> V_48 ) ;
if ( ! V_45 )
V_45 = F_40 ( V_62 , & V_58 -> V_28 ) ;
if ( ! V_45 ) {
V_62 = F_35 ( V_26 * sizeof( int ) ) ;
if ( V_43 -> V_65 < V_62 )
V_62 = V_43 -> V_65 ;
V_43 -> V_60 += V_62 ;
V_43 -> V_65 -= V_62 ;
}
}
if ( V_26 < V_70 || ( V_70 && V_69 <= 0 ) )
V_43 -> V_64 |= V_66 ;
F_19 ( V_39 ) ;
}
struct V_20 * F_47 ( struct V_20 * V_23 )
{
struct V_20 * V_77 ;
int V_26 ;
if ( ! V_23 )
return NULL ;
V_77 = F_48 ( V_23 , F_49 ( struct V_20 , V_35 [ V_23 -> V_32 ] ) ,
V_30 ) ;
if ( V_77 ) {
for ( V_26 = 0 ; V_26 < V_23 -> V_32 ; V_26 ++ )
F_46 ( V_23 -> V_35 [ V_26 ] ) ;
V_77 -> V_33 = V_77 -> V_32 ;
V_77 -> V_34 = F_17 ( V_23 -> V_34 ) ;
}
return V_77 ;
}
