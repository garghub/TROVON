static inline void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 0 ;
}
static void F_2 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
F_1 ( & V_9 -> V_2 , V_12 , V_11 -> V_4 ) ;
F_3 ( V_9 , V_11 -> V_13 , V_12 , 1 ) ;
}
static void F_4 ( struct V_8 * V_9 ,
struct V_14 * V_15 )
{
F_1 ( & V_9 -> V_2 , V_16 , V_15 -> V_4 ) ;
V_9 -> V_17 . V_18 . V_19 = V_15 -> V_19 ;
}
static int F_5 ( struct V_20 * V_21 , struct V_14 * V_15 )
{
struct V_22 V_23 ;
struct V_24 V_25 [ 1 ] ;
T_2 V_26 ;
int V_27 ;
struct V_8 V_28 ;
V_26 = 0 ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
F_4 ( & V_28 , V_15 ) ;
F_6 ( & V_28 , 1 ) ;
V_25 [ 0 ] . V_29 = & V_28 ;
V_25 [ 0 ] . V_30 = sizeof( V_28 ) ;
V_26 += sizeof( V_28 ) ;
V_27 = F_7 ( V_21 -> V_31 . V_32 , & V_23 , V_25 ,
1 , V_26 ) ;
if ( V_27 != V_26 ) {
F_8 ( & V_21 -> V_31 , V_33 ) ;
if ( V_27 >= 0 )
return - V_34 ;
return V_27 ;
}
F_9 ( V_15 ) ;
return V_26 ;
}
static int F_10 ( struct V_20 * V_21 , struct V_10 * V_11 )
{
struct V_13 * V_13 = V_11 -> V_13 ;
struct V_8 V_28 ;
struct V_35 * V_36 = NULL ;
struct V_24 * V_25 = NULL ;
int V_37 = 0 ;
int V_27 = 0 ;
T_2 V_26 ;
struct V_22 V_23 ;
V_26 = 0 ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
if ( V_11 -> type == V_38 )
V_37 = 2 + V_13 -> V_39 ;
else
V_37 = 2 ;
V_25 = F_11 ( V_37 , sizeof( * V_25 ) , V_40 ) ;
if ( ! V_25 ) {
F_8 ( & V_21 -> V_31 , V_41 ) ;
V_27 = - V_42 ;
goto V_43;
}
V_37 = 0 ;
F_2 ( & V_28 , V_11 ) ;
F_12 ( L_1 ,
V_28 . V_2 . V_4 , V_13 ) ;
F_6 ( & V_28 , 1 ) ;
V_25 [ V_37 ] . V_29 = & V_28 ;
V_25 [ V_37 ] . V_30 = sizeof( V_28 ) ;
V_37 ++ ;
V_26 += sizeof( V_28 ) ;
if ( V_11 -> type != V_38 &&
F_13 ( V_13 -> V_44 ) && V_13 -> V_45 > 0 ) {
V_25 [ V_37 ] . V_29 = V_13 -> V_46 ;
V_25 [ V_37 ] . V_30 = V_13 -> V_45 ;
V_37 ++ ;
V_26 += V_13 -> V_45 ;
} else if ( V_11 -> type == V_38 &&
F_13 ( V_13 -> V_44 ) ) {
int V_47 ;
for ( V_47 = 0 ; V_47 < V_13 -> V_39 ; V_47 ++ ) {
V_25 [ V_37 ] . V_29 = V_13 -> V_46 +
V_13 -> V_48 [ V_47 ] . V_49 ;
V_25 [ V_37 ] . V_30 =
V_13 -> V_48 [ V_47 ] . V_45 ;
V_37 ++ ;
V_26 += V_13 -> V_48 [ V_47 ] . V_45 ;
}
if ( V_26 != sizeof( V_28 ) + V_13 -> V_45 ) {
F_8 ( & V_21 -> V_31 , V_33 ) ;
V_27 = - V_34 ;
goto V_43;
}
}
if ( V_11 -> type == V_38 ) {
T_3 V_50 = 0 ;
V_36 = F_14 ( V_13 , & V_50 ) ;
if ( ! V_36 ) {
F_8 ( & V_21 -> V_31 ,
V_41 ) ;
V_27 = - V_42 ;
goto V_43;
}
V_25 [ V_37 ] . V_29 = V_36 ;
V_25 [ V_37 ] . V_30 = V_50 ;
V_26 += V_50 ;
V_37 ++ ;
}
V_27 = F_7 ( V_21 -> V_31 . V_32 , & V_23 ,
V_25 , V_37 , V_26 ) ;
if ( V_27 != V_26 ) {
F_8 ( & V_21 -> V_31 , V_33 ) ;
if ( V_27 >= 0 )
V_27 = - V_34 ;
goto V_43;
}
V_43:
F_9 ( V_25 ) ;
F_9 ( V_36 ) ;
F_15 ( V_11 ) ;
if ( V_27 < 0 )
return V_27 ;
return V_26 ;
}
static int F_16 ( struct V_20 * V_21 )
{
unsigned long V_51 ;
struct V_52 * V_53 ;
T_2 V_54 = 0 ;
int V_27 = 0 ;
F_17 ( & V_21 -> V_55 , V_51 ) ;
while ( ! F_18 ( & V_21 -> V_56 ) ) {
V_53 = F_19 ( & V_21 -> V_56 , struct V_52 ,
V_57 ) ;
F_20 ( & V_53 -> V_57 ) ;
F_21 ( & V_21 -> V_55 , V_51 ) ;
switch ( V_53 -> type ) {
case V_58 :
V_27 = F_10 ( V_21 , V_53 -> V_59 ) ;
break;
case V_60 :
V_27 = F_5 ( V_21 , V_53 -> V_17 ) ;
break;
}
F_9 ( V_53 ) ;
if ( V_27 < 0 )
return V_27 ;
V_54 += V_27 ;
F_17 ( & V_21 -> V_55 , V_51 ) ;
}
F_21 ( & V_21 -> V_55 , V_51 ) ;
return V_54 ;
}
int F_22 ( void * V_61 )
{
struct V_62 * V_31 = (struct V_62 * ) V_61 ;
struct V_20 * V_21 = F_23 ( V_31 , struct V_20 , V_31 ) ;
int V_27 ;
while ( ! F_24 () ) {
if ( F_25 ( & V_21 -> V_31 ) )
break;
V_27 = F_16 ( V_21 ) ;
if ( V_27 < 0 ) {
F_26 ( L_2 , V_27 ) ;
break;
}
F_27 ( V_21 -> V_63 ,
( ! F_18 ( & V_21 -> V_56 ) ||
F_24 () ) ) ;
}
return 0 ;
}
void F_28 ( struct V_20 * V_21 , T_1 V_4 , T_1 V_19 )
{
struct V_52 * V_53 ;
struct V_14 * V_15 ;
V_53 = F_29 ( sizeof( * V_53 ) , V_64 ) ;
if ( ! V_53 ) {
F_8 ( & V_21 -> V_31 , V_65 ) ;
return;
}
V_15 = F_29 ( sizeof( * V_15 ) , V_64 ) ;
if ( ! V_15 ) {
F_9 ( V_53 ) ;
F_8 ( & V_21 -> V_31 , V_65 ) ;
return;
}
V_15 -> V_4 = V_4 ;
V_15 -> V_19 = V_19 ;
V_53 -> type = V_60 ;
V_53 -> V_17 = V_15 ;
F_30 ( & V_53 -> V_57 , & V_21 -> V_56 ) ;
}
void F_31 ( struct V_20 * V_21 , struct V_10 * V_11 )
{
struct V_52 * V_53 ;
V_53 = F_29 ( sizeof( * V_53 ) , V_64 ) ;
if ( ! V_53 ) {
F_8 ( & V_21 -> V_31 , V_65 ) ;
return;
}
V_53 -> type = V_58 ;
V_53 -> V_59 = V_11 ;
F_30 ( & V_53 -> V_57 , & V_21 -> V_56 ) ;
}
