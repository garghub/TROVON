int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 ,
char * V_7 )
{
if ( ( V_2 -> V_8 -> V_9 == 0 ) ||
( V_2 -> V_8 -> V_10 == NULL ) )
return - V_11 ;
if ( V_6 -> V_12 . V_13 < V_2 -> V_8 -> V_9 ) {
V_6 -> V_12 . V_13 = V_2 -> V_8 -> V_9 ;
return - V_14 ;
}
V_6 -> V_12 . V_13 = V_2 -> V_8 -> V_9 ;
memcpy ( V_7 , V_2 -> V_8 -> V_10 ,
sizeof( struct V_15 ) * V_6 -> V_12 . V_13 ) ;
return 0 ;
}
static int F_2 ( T_1 args )
{
int V_16 = args & V_17 ;
int type = ( args & V_18 ) >> 12 ;
return V_16 * V_19 [ type ] ;
}
static int F_3 ( T_1 args , struct V_20 * V_21 )
{
int V_16 = V_21 -> V_13 ;
int V_22 = args & V_17 ;
int type = ( args & V_18 ) >> 12 ;
if ( V_22 < V_16 )
V_16 = V_22 ;
return V_16 * V_19 [ type ] ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_23 ,
const struct V_15 * * V_24 )
{
const struct V_15 * V_25 ;
int V_26 , V_27 ;
V_25 = NULL ;
for ( V_26 = 0 ; V_26 < V_2 -> V_8 -> V_9 ; V_26 ++ ) {
if ( V_23 == V_2 -> V_8 -> V_10 [ V_26 ] . V_23 ) {
V_25 = & V_2 -> V_8 -> V_10 [ V_26 ] ;
break;
}
}
V_27 = 0 ;
if ( V_25 ) {
if ( F_5 ( V_23 ) ) {
int V_28 = 0 ;
if ( V_25 -> V_29 [ 0 ] == '\0' )
V_28 = sizeof( V_30 ) ;
V_27 = F_2 ( V_25 -> V_31 ) ;
if ( ( V_25 -> V_31 & V_32 ) &&
( ( V_27 + V_28 ) <= V_33 ) )
V_27 = 0 ;
} else {
V_27 = F_2 ( V_25 -> V_34 ) ;
if ( ( V_25 -> V_34 & V_32 ) &&
( V_27 <= V_33 ) )
V_27 = 0 ;
}
}
* V_24 = V_25 ;
return V_27 ;
}
static int F_6 ( struct V_20 * V_21 , unsigned int V_23 ,
const struct V_15 * V_25 ,
T_2 V_35 , struct V_1 * V_2 ,
struct V_3 * V_4 , int V_27 )
{
char * V_7 ;
int V_36 ;
if ( F_5 ( V_23 ) ) {
if ( ! V_21 -> V_37 && V_21 -> V_13 != 0 )
return - V_38 ;
if ( V_21 -> V_13 > ( V_25 -> V_31 & V_17 ) )
return - V_14 ;
} else if ( ! V_21 -> V_37 )
return - V_38 ;
V_7 = F_7 ( V_27 , V_39 ) ;
if ( ! V_7 )
return - V_40 ;
if ( F_5 ( V_23 ) && ( V_21 -> V_13 != 0 ) ) {
if ( F_8 ( V_7 , V_21 -> V_37 , V_27 ) ) {
V_36 = - V_38 ;
goto V_41;
}
}
V_36 = V_35 ( V_2 , V_4 , (union V_5 * ) V_21 , V_7 ) ;
if ( ! V_36 && F_9 ( V_23 ) ) {
if ( ! ( V_25 -> V_34 & V_32 ) )
V_27 = F_3 ( V_25 -> V_34 , V_21 ) ;
if ( F_10 ( V_21 -> V_37 , V_7 , V_27 ) )
V_36 = - V_38 ;
}
V_41:
F_11 ( V_7 ) ;
return V_36 ;
}
int F_12 ( struct V_1 * V_2 , struct V_42 * V_43 ,
unsigned int V_23 , struct V_3 * V_4 ,
T_2 V_35 )
{
int V_27 = 0 , V_44 = - V_45 ;
const struct V_15 * V_25 ;
V_27 = F_4 ( V_2 , V_23 , & V_25 ) ;
if ( V_27 == 0 ) {
V_44 = V_35 ( V_2 , V_4 , & ( V_43 -> V_46 ) , ( char * ) & ( V_43 -> V_46 ) ) ;
} else {
V_44 = F_6 ( & V_43 -> V_46 . V_12 , V_23 , V_25 ,
V_35 , V_2 , V_4 , V_27 ) ;
}
if ( V_44 == - V_47 )
V_44 = F_13 ( V_2 ) ;
return V_44 ;
}
int F_14 ( struct V_1 * V_2 , struct V_42 * V_43 ,
unsigned int V_23 , struct V_3 * V_4 ,
T_2 V_35 )
{
const struct V_15 * V_25 ;
int V_44 , V_27 ;
V_27 = F_4 ( V_2 , V_23 , & V_25 ) ;
if ( V_27 == 0 ) {
V_44 = V_35 ( V_2 , V_4 , & ( V_43 -> V_46 ) , ( char * ) & ( V_43 -> V_46 ) ) ;
} else {
struct V_48 * V_49 ;
struct V_20 V_21 ;
V_49 = (struct V_48 * ) & V_43 -> V_46 . V_12 ;
V_21 . V_37 = F_15 ( V_49 -> V_37 ) ;
V_21 . V_13 = V_49 -> V_13 ;
V_21 . V_50 = V_49 -> V_50 ;
V_44 = F_6 ( & V_21 , V_23 , V_25 ,
V_35 , V_2 , V_4 , V_27 ) ;
V_49 -> V_37 = F_16 ( V_21 . V_37 ) ;
V_49 -> V_13 = V_21 . V_13 ;
V_49 -> V_50 = V_21 . V_50 ;
}
if ( V_44 == - V_47 )
V_44 = F_13 ( V_2 ) ;
return V_44 ;
}
