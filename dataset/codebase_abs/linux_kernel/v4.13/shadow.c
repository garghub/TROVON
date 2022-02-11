static bool
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_5 )
{
const T_1 V_6 = ( V_5 + 3 ) & ~ 3 ;
const T_1 V_7 = V_2 -> V_8 ;
void * V_9 = V_4 -> V_9 ;
if ( F_2 ( V_2 , V_6 ) > 0 ) {
T_1 V_10 = V_4 -> V_11 -> V_10 ( V_9 , V_7 , V_6 - V_7 , V_2 ) ;
V_2 -> V_8 = V_7 + V_10 ;
}
return V_2 -> V_8 >= V_5 ;
}
static int
F_3 ( struct V_1 * V_2 , int V_12 , T_1 V_13 , struct V_3 * V_4 )
{
struct V_14 * V_15 = & V_2 -> V_15 ;
struct V_16 V_17 ;
int V_18 = 1 ;
if ( V_4 -> V_11 -> V_19 ) {
V_17 . V_20 = 0 ;
V_17 . type = 0 ;
V_17 . V_8 = V_4 -> V_11 -> V_8 ( V_4 -> V_9 ) ;
V_17 . V_21 = 1 ;
} else {
if ( ! F_1 ( V_2 , V_4 , V_13 + 0x1000 ) ) {
F_4 ( V_15 , L_1 ,
V_13 ) ;
return 0 ;
}
if ( ! V_16 ( V_2 , V_12 , & V_17 ) ) {
F_4 ( V_15 , L_2 , V_12 ) ;
return 0 ;
}
}
F_4 ( V_15 , L_3 ,
V_17 . V_20 , V_17 . type , V_17 . V_8 ) ;
if ( ! F_1 ( V_2 , V_4 , V_17 . V_8 ) ) {
F_4 ( V_15 , L_4 , V_17 . V_20 ) ;
return 0 ;
}
switch ( V_17 . type ) {
case 0x00 :
if ( ! V_4 -> V_11 -> V_22 &&
F_5 ( & V_2 -> V_9 [ V_17 . V_20 ] , V_17 . V_8 ) ) {
F_4 ( V_15 , L_5 ,
V_17 . V_20 ) ;
if ( ! V_4 -> V_11 -> V_23 ) {
if ( V_4 -> V_11 -> V_24 )
V_18 += 1 ;
V_18 += 1 ;
} else
return 0 ;
} else {
V_18 += 3 ;
}
break;
default:
V_18 += 3 ;
break;
}
if ( ! V_17 . V_21 )
V_18 += F_3 ( V_2 , V_12 + 1 , V_13 + V_17 . V_8 , V_4 ) ;
return V_18 ;
}
static int
F_6 ( struct V_1 * V_2 , struct V_3 * V_4 , const char * V_25 )
{
const struct V_26 * V_11 = V_4 -> V_11 ;
struct V_14 * V_15 = & V_2 -> V_15 ;
if ( V_11 -> V_25 ) {
F_4 ( V_15 , L_6 , V_25 ? V_25 : V_11 -> V_25 ) ;
if ( V_11 -> V_27 ) {
V_4 -> V_9 = V_11 -> V_27 ( V_2 , V_25 ) ;
if ( F_7 ( V_4 -> V_9 ) ) {
V_4 -> V_9 = NULL ;
return 0 ;
}
}
V_4 -> V_18 = F_3 ( V_2 , 0 , 0 , V_4 ) ;
if ( V_11 -> V_28 )
V_11 -> V_28 ( V_4 -> V_9 ) ;
F_4 ( V_15 , L_7 , V_4 -> V_18 ) ;
V_4 -> V_9 = V_2 -> V_9 ;
V_4 -> V_8 = V_2 -> V_8 ;
V_2 -> V_9 = NULL ;
V_2 -> V_8 = 0 ;
}
return V_4 -> V_18 ;
}
static T_1
F_8 ( void * V_9 , T_1 V_13 , T_1 V_29 , struct V_1 * V_2 )
{
const struct V_30 * V_31 = V_9 ;
if ( V_13 + V_29 <= V_31 -> V_8 ) {
memcpy ( V_2 -> V_9 + V_13 , V_31 -> V_9 + V_13 , V_29 ) ;
return V_29 ;
}
return 0 ;
}
static void *
F_9 ( struct V_1 * V_2 , const char * V_25 )
{
struct V_32 * V_33 = V_2 -> V_15 . V_32 -> V_33 ;
const struct V_30 * V_31 ;
int V_34 = F_10 ( & V_31 , V_25 , V_33 ) ;
if ( V_34 )
return F_11 ( - V_35 ) ;
return ( void * ) V_31 ;
}
int
F_12 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_15 ;
struct V_36 * V_32 = V_15 -> V_32 ;
struct V_3 V_37 [] = {
{ 0 , & V_38 } ,
{ 0 , & V_39 } ,
{ 0 , & V_40 } ,
{ 0 , & V_41 } ,
{ 4 , & V_42 } ,
{ 1 , & V_43 } ,
{ 1 , & V_44 } ,
{}
} , * V_4 , * V_45 = NULL ;
const char * V_46 ;
char * V_47 ;
int V_48 ;
V_46 = F_13 ( V_32 -> V_49 , L_8 , & V_48 ) ;
V_47 = V_46 ? F_14 ( V_46 , V_48 , V_50 ) : NULL ;
if ( V_47 ) {
for ( V_4 = V_37 ; V_4 -> V_11 ; V_4 ++ ) {
if ( V_4 -> V_11 -> V_25 &&
! strcasecmp ( V_47 , V_4 -> V_11 -> V_25 ) ) {
V_45 = V_4 ;
if ( F_6 ( V_2 , V_4 , NULL ) )
break;
}
}
if ( ! V_45 && ( V_45 = V_4 ) ) {
V_4 -> V_11 = & V_51 ;
F_6 ( V_2 , V_4 , V_47 ) ;
V_4 -> V_11 = NULL ;
}
if ( ! V_45 -> V_18 ) {
F_15 ( V_15 , L_9 , V_47 ) ;
F_16 ( V_47 ) ;
V_47 = NULL ;
}
}
if ( ! V_45 || ! V_45 -> V_18 ) {
for ( V_4 = V_37 , V_45 = V_4 ; V_4 -> V_11 ; V_4 ++ ) {
if ( ! V_4 -> V_52 || V_45 -> V_18 < V_4 -> V_52 ) {
if ( F_6 ( V_2 , V_4 , NULL ) ) {
if ( V_4 -> V_18 > V_45 -> V_18 )
V_45 = V_4 ;
}
}
}
}
for ( V_4 = V_37 ; V_4 -> V_11 ; V_4 ++ ) {
if ( V_4 != V_45 )
F_16 ( V_4 -> V_9 ) ;
}
if ( ! V_45 -> V_18 ) {
F_15 ( V_15 , L_10 ) ;
return - V_53 ;
}
F_4 ( V_15 , L_11 , V_45 -> V_11 ?
V_45 -> V_11 -> V_25 : V_47 ) ;
V_2 -> V_9 = V_45 -> V_9 ;
V_2 -> V_8 = V_45 -> V_8 ;
F_16 ( V_47 ) ;
return 0 ;
}
