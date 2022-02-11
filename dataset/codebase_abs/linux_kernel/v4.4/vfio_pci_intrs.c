static void F_1 ( void * V_1 , void * V_2 )
{
struct V_3 * V_4 = V_1 ;
if ( F_2 ( F_3 ( V_4 ) && ! V_4 -> V_5 ) )
F_4 ( V_4 -> V_6 [ 0 ] . V_7 , 1 ) ;
}
void F_5 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned long V_10 ;
F_6 ( & V_4 -> V_11 , V_10 ) ;
if ( F_7 ( ! F_3 ( V_4 ) ) ) {
if ( V_4 -> V_12 )
F_8 ( V_9 , 0 ) ;
} else if ( ! V_4 -> V_6 [ 0 ] . V_13 ) {
if ( V_4 -> V_12 )
F_8 ( V_9 , 0 ) ;
else
F_9 ( V_9 -> V_14 ) ;
V_4 -> V_6 [ 0 ] . V_13 = true ;
}
F_10 ( & V_4 -> V_11 , V_10 ) ;
}
static int F_11 ( void * V_1 , void * V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned long V_10 ;
int V_15 = 0 ;
F_6 ( & V_4 -> V_11 , V_10 ) ;
if ( F_7 ( ! F_3 ( V_4 ) ) ) {
if ( V_4 -> V_12 )
F_8 ( V_9 , 1 ) ;
} else if ( V_4 -> V_6 [ 0 ] . V_13 && ! V_4 -> V_5 ) {
if ( V_4 -> V_12 ) {
if ( ! F_12 ( V_9 ) )
V_15 = 1 ;
} else
F_13 ( V_9 -> V_14 ) ;
V_4 -> V_6 [ 0 ] . V_13 = ( V_15 > 0 ) ;
}
F_10 ( & V_4 -> V_11 , V_10 ) ;
return V_15 ;
}
void F_14 ( struct V_3 * V_4 )
{
if ( F_11 ( V_4 , NULL ) > 0 )
F_1 ( V_4 , NULL ) ;
}
static T_1 F_15 ( int V_14 , void * V_16 )
{
struct V_3 * V_4 = V_16 ;
unsigned long V_10 ;
int V_15 = V_17 ;
F_6 ( & V_4 -> V_11 , V_10 ) ;
if ( ! V_4 -> V_12 ) {
F_9 ( V_4 -> V_9 -> V_14 ) ;
V_4 -> V_6 [ 0 ] . V_13 = true ;
V_15 = V_18 ;
} else if ( ! V_4 -> V_6 [ 0 ] . V_13 &&
F_16 ( V_4 -> V_9 ) ) {
V_4 -> V_6 [ 0 ] . V_13 = true ;
V_15 = V_18 ;
}
F_10 ( & V_4 -> V_11 , V_10 ) ;
if ( V_15 == V_18 )
F_1 ( V_4 , NULL ) ;
return V_15 ;
}
static int F_17 ( struct V_3 * V_4 )
{
if ( ! F_18 ( V_4 ) )
return - V_19 ;
if ( ! V_4 -> V_9 -> V_14 )
return - V_20 ;
V_4 -> V_6 = F_19 ( sizeof( struct V_21 ) , V_22 ) ;
if ( ! V_4 -> V_6 )
return - V_23 ;
V_4 -> V_24 = 1 ;
V_4 -> V_6 [ 0 ] . V_13 = V_4 -> V_5 ;
if ( V_4 -> V_12 )
F_8 ( V_4 -> V_9 , ! V_4 -> V_6 [ 0 ] . V_13 ) ;
V_4 -> V_25 = V_26 ;
return 0 ;
}
static int F_20 ( struct V_3 * V_4 , int V_27 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned long V_28 = V_29 ;
struct V_30 * V_7 ;
unsigned long V_10 ;
int V_15 ;
if ( V_4 -> V_6 [ 0 ] . V_7 ) {
F_21 ( V_9 -> V_14 , V_4 ) ;
F_22 ( V_4 -> V_6 [ 0 ] . V_31 ) ;
F_23 ( V_4 -> V_6 [ 0 ] . V_7 ) ;
V_4 -> V_6 [ 0 ] . V_7 = NULL ;
}
if ( V_27 < 0 )
return 0 ;
V_4 -> V_6 [ 0 ] . V_31 = F_24 ( V_22 , L_1 ,
F_25 ( V_9 ) ) ;
if ( ! V_4 -> V_6 [ 0 ] . V_31 )
return - V_23 ;
V_7 = F_26 ( V_27 ) ;
if ( F_27 ( V_7 ) ) {
F_22 ( V_4 -> V_6 [ 0 ] . V_31 ) ;
return F_28 ( V_7 ) ;
}
V_4 -> V_6 [ 0 ] . V_7 = V_7 ;
if ( ! V_4 -> V_12 )
V_28 = 0 ;
V_15 = F_29 ( V_9 -> V_14 , F_15 ,
V_28 , V_4 -> V_6 [ 0 ] . V_31 , V_4 ) ;
if ( V_15 ) {
V_4 -> V_6 [ 0 ] . V_7 = NULL ;
F_22 ( V_4 -> V_6 [ 0 ] . V_31 ) ;
F_23 ( V_7 ) ;
return V_15 ;
}
F_6 ( & V_4 -> V_11 , V_10 ) ;
if ( ! V_4 -> V_12 && V_4 -> V_6 [ 0 ] . V_13 )
F_9 ( V_9 -> V_14 ) ;
F_10 ( & V_4 -> V_11 , V_10 ) ;
return 0 ;
}
static void F_30 ( struct V_3 * V_4 )
{
F_20 ( V_4 , - 1 ) ;
F_31 ( & V_4 -> V_6 [ 0 ] . V_32 ) ;
F_31 ( & V_4 -> V_6 [ 0 ] . V_33 ) ;
V_4 -> V_25 = V_34 ;
V_4 -> V_24 = 0 ;
F_22 ( V_4 -> V_6 ) ;
}
static T_1 F_32 ( int V_14 , void * V_35 )
{
struct V_30 * V_7 = V_35 ;
F_4 ( V_7 , 1 ) ;
return V_18 ;
}
static int F_33 ( struct V_3 * V_4 , int V_36 , bool V_37 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_15 ;
if ( ! F_18 ( V_4 ) )
return - V_19 ;
V_4 -> V_6 = F_19 ( V_36 * sizeof( struct V_21 ) , V_22 ) ;
if ( ! V_4 -> V_6 )
return - V_23 ;
if ( V_37 ) {
int V_38 ;
V_4 -> V_37 = F_19 ( V_36 * sizeof( struct V_39 ) ,
V_22 ) ;
if ( ! V_4 -> V_37 ) {
F_22 ( V_4 -> V_6 ) ;
return - V_23 ;
}
for ( V_38 = 0 ; V_38 < V_36 ; V_38 ++ )
V_4 -> V_37 [ V_38 ] . V_40 = V_38 ;
V_15 = F_34 ( V_9 , V_4 -> V_37 , 1 , V_36 ) ;
if ( V_15 < V_36 ) {
if ( V_15 > 0 )
F_35 ( V_9 ) ;
F_22 ( V_4 -> V_37 ) ;
F_22 ( V_4 -> V_6 ) ;
return V_15 ;
}
} else {
V_15 = F_36 ( V_9 , 1 , V_36 ) ;
if ( V_15 < V_36 ) {
if ( V_15 > 0 )
F_37 ( V_9 ) ;
F_22 ( V_4 -> V_6 ) ;
return V_15 ;
}
}
V_4 -> V_24 = V_36 ;
V_4 -> V_25 = V_37 ? V_41 :
V_42 ;
if ( ! V_37 ) {
V_4 -> V_43 = F_38 ( V_36 * 2 - 1 ) - 1 ;
}
return 0 ;
}
static int F_39 ( struct V_3 * V_4 ,
int V_44 , int V_27 , bool V_37 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_14 = V_37 ? V_4 -> V_37 [ V_44 ] . V_44 : V_9 -> V_14 + V_44 ;
char * V_31 = V_37 ? L_2 : L_3 ;
struct V_30 * V_7 ;
int V_15 ;
if ( V_44 >= V_4 -> V_24 )
return - V_19 ;
if ( V_4 -> V_6 [ V_44 ] . V_7 ) {
F_21 ( V_14 , V_4 -> V_6 [ V_44 ] . V_7 ) ;
F_40 ( & V_4 -> V_6 [ V_44 ] . V_45 ) ;
F_22 ( V_4 -> V_6 [ V_44 ] . V_31 ) ;
F_23 ( V_4 -> V_6 [ V_44 ] . V_7 ) ;
V_4 -> V_6 [ V_44 ] . V_7 = NULL ;
}
if ( V_27 < 0 )
return 0 ;
V_4 -> V_6 [ V_44 ] . V_31 = F_24 ( V_22 , L_4 ,
V_31 , V_44 , F_25 ( V_9 ) ) ;
if ( ! V_4 -> V_6 [ V_44 ] . V_31 )
return - V_23 ;
V_7 = F_26 ( V_27 ) ;
if ( F_27 ( V_7 ) ) {
F_22 ( V_4 -> V_6 [ V_44 ] . V_31 ) ;
return F_28 ( V_7 ) ;
}
if ( V_37 ) {
struct V_46 V_47 ;
F_41 ( V_14 , & V_47 ) ;
F_42 ( V_14 , & V_47 ) ;
}
V_15 = F_29 ( V_14 , F_32 , 0 ,
V_4 -> V_6 [ V_44 ] . V_31 , V_7 ) ;
if ( V_15 ) {
F_22 ( V_4 -> V_6 [ V_44 ] . V_31 ) ;
F_23 ( V_7 ) ;
return V_15 ;
}
V_4 -> V_6 [ V_44 ] . V_45 . V_48 = V_7 ;
V_4 -> V_6 [ V_44 ] . V_45 . V_14 = V_14 ;
V_15 = F_43 ( & V_4 -> V_6 [ V_44 ] . V_45 ) ;
if ( F_7 ( V_15 ) )
F_44 ( & V_9 -> V_49 ,
L_5 ,
V_4 -> V_6 [ V_44 ] . V_45 . V_48 , V_15 ) ;
V_4 -> V_6 [ V_44 ] . V_7 = V_7 ;
return 0 ;
}
static int F_45 ( struct V_3 * V_4 , unsigned V_50 ,
unsigned V_51 , T_2 * V_52 , bool V_37 )
{
int V_38 , V_53 , V_15 = 0 ;
if ( V_50 + V_51 > V_4 -> V_24 )
return - V_19 ;
for ( V_38 = 0 , V_53 = V_50 ; V_38 < V_51 && ! V_15 ; V_38 ++ , V_53 ++ ) {
int V_27 = V_52 ? V_52 [ V_38 ] : - 1 ;
V_15 = F_39 ( V_4 , V_53 , V_27 , V_37 ) ;
}
if ( V_15 ) {
for ( -- V_53 ; V_53 >= V_50 ; V_53 -- )
F_39 ( V_4 , V_53 , - 1 , V_37 ) ;
}
return V_15 ;
}
static void F_46 ( struct V_3 * V_4 , bool V_37 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_38 ;
F_45 ( V_4 , 0 , V_4 -> V_24 , NULL , V_37 ) ;
for ( V_38 = 0 ; V_38 < V_4 -> V_24 ; V_38 ++ ) {
F_31 ( & V_4 -> V_6 [ V_38 ] . V_32 ) ;
F_31 ( & V_4 -> V_6 [ V_38 ] . V_33 ) ;
}
if ( V_37 ) {
F_35 ( V_4 -> V_9 ) ;
F_22 ( V_4 -> V_37 ) ;
} else
F_37 ( V_9 ) ;
V_4 -> V_25 = V_34 ;
V_4 -> V_24 = 0 ;
F_22 ( V_4 -> V_6 ) ;
}
static int F_47 ( struct V_3 * V_4 ,
unsigned V_54 , unsigned V_50 ,
unsigned V_51 , T_3 V_10 , void * V_55 )
{
if ( ! F_3 ( V_4 ) || V_50 != 0 || V_51 != 1 )
return - V_19 ;
if ( V_10 & V_56 ) {
F_14 ( V_4 ) ;
} else if ( V_10 & V_57 ) {
T_4 V_32 = * ( T_4 * ) V_55 ;
if ( V_32 )
F_14 ( V_4 ) ;
} else if ( V_10 & V_58 ) {
T_2 V_27 = * ( T_2 * ) V_55 ;
if ( V_27 >= 0 )
return F_48 ( ( void * ) V_4 ,
F_11 ,
F_1 , NULL ,
& V_4 -> V_6 [ 0 ] . V_32 , V_27 ) ;
F_31 ( & V_4 -> V_6 [ 0 ] . V_32 ) ;
}
return 0 ;
}
static int F_49 ( struct V_3 * V_4 ,
unsigned V_54 , unsigned V_50 ,
unsigned V_51 , T_3 V_10 , void * V_55 )
{
if ( ! F_3 ( V_4 ) || V_50 != 0 || V_51 != 1 )
return - V_19 ;
if ( V_10 & V_56 ) {
F_5 ( V_4 ) ;
} else if ( V_10 & V_57 ) {
T_4 V_33 = * ( T_4 * ) V_55 ;
if ( V_33 )
F_5 ( V_4 ) ;
} else if ( V_10 & V_58 ) {
return - V_59 ;
}
return 0 ;
}
static int F_50 ( struct V_3 * V_4 ,
unsigned V_54 , unsigned V_50 ,
unsigned V_51 , T_3 V_10 , void * V_55 )
{
if ( F_3 ( V_4 ) && ! V_51 && ( V_10 & V_56 ) ) {
F_30 ( V_4 ) ;
return 0 ;
}
if ( ! ( F_3 ( V_4 ) || F_18 ( V_4 ) ) || V_50 != 0 || V_51 != 1 )
return - V_19 ;
if ( V_10 & V_58 ) {
T_2 V_27 = * ( T_2 * ) V_55 ;
int V_15 ;
if ( F_3 ( V_4 ) )
return F_20 ( V_4 , V_27 ) ;
V_15 = F_17 ( V_4 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_20 ( V_4 , V_27 ) ;
if ( V_15 )
F_30 ( V_4 ) ;
return V_15 ;
}
if ( ! F_3 ( V_4 ) )
return - V_19 ;
if ( V_10 & V_56 ) {
F_1 ( V_4 , NULL ) ;
} else if ( V_10 & V_57 ) {
T_4 V_7 = * ( T_4 * ) V_55 ;
if ( V_7 )
F_1 ( V_4 , NULL ) ;
}
return 0 ;
}
static int F_51 ( struct V_3 * V_4 ,
unsigned V_54 , unsigned V_50 ,
unsigned V_51 , T_3 V_10 , void * V_55 )
{
int V_38 ;
bool V_37 = ( V_54 == V_41 ) ? true : false ;
if ( F_52 ( V_4 , V_54 ) && ! V_51 && ( V_10 & V_56 ) ) {
F_46 ( V_4 , V_37 ) ;
return 0 ;
}
if ( ! ( F_52 ( V_4 , V_54 ) || F_18 ( V_4 ) ) )
return - V_19 ;
if ( V_10 & V_58 ) {
T_2 * V_52 = V_55 ;
int V_15 ;
if ( V_4 -> V_25 == V_54 )
return F_45 ( V_4 , V_50 , V_51 ,
V_52 , V_37 ) ;
V_15 = F_33 ( V_4 , V_50 + V_51 , V_37 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_45 ( V_4 , V_50 , V_51 , V_52 , V_37 ) ;
if ( V_15 )
F_46 ( V_4 , V_37 ) ;
return V_15 ;
}
if ( ! F_52 ( V_4 , V_54 ) || V_50 + V_51 > V_4 -> V_24 )
return - V_19 ;
for ( V_38 = V_50 ; V_38 < V_50 + V_51 ; V_38 ++ ) {
if ( ! V_4 -> V_6 [ V_38 ] . V_7 )
continue;
if ( V_10 & V_56 ) {
F_4 ( V_4 -> V_6 [ V_38 ] . V_7 , 1 ) ;
} else if ( V_10 & V_57 ) {
T_4 * V_60 = V_55 ;
if ( V_60 [ V_38 - V_50 ] )
F_4 ( V_4 -> V_6 [ V_38 ] . V_7 , 1 ) ;
}
}
return 0 ;
}
static int F_53 ( struct V_30 * * V_6 ,
T_3 V_10 , void * V_55 )
{
T_2 V_27 = * ( T_2 * ) V_55 ;
if ( ! ( V_10 & V_61 ) )
return - V_19 ;
if ( V_10 & V_56 ) {
if ( * V_6 )
F_4 ( * V_6 , 1 ) ;
return 0 ;
} else if ( V_10 & V_57 ) {
T_4 V_7 = * ( T_4 * ) V_55 ;
if ( V_7 && * V_6 )
F_4 ( * V_6 , 1 ) ;
return 0 ;
}
if ( V_27 == - 1 ) {
if ( * V_6 )
F_23 ( * V_6 ) ;
* V_6 = NULL ;
return 0 ;
} else if ( V_27 >= 0 ) {
struct V_30 * V_62 ;
V_62 = F_26 ( V_27 ) ;
if ( F_27 ( V_62 ) )
return F_28 ( V_62 ) ;
if ( * V_6 )
F_23 ( * V_6 ) ;
* V_6 = V_62 ;
return 0 ;
} else
return - V_19 ;
}
static int F_54 ( struct V_3 * V_4 ,
unsigned V_54 , unsigned V_50 ,
unsigned V_51 , T_3 V_10 , void * V_55 )
{
if ( V_54 != V_63 )
return - V_19 ;
return F_53 ( & V_4 -> V_64 , V_10 , V_55 ) ;
}
static int F_55 ( struct V_3 * V_4 ,
unsigned V_54 , unsigned V_50 ,
unsigned V_51 , T_3 V_10 , void * V_55 )
{
if ( V_54 != V_65 || V_50 != 0 || V_51 != 1 )
return - V_19 ;
return F_53 ( & V_4 -> V_66 , V_10 , V_55 ) ;
}
int F_56 ( struct V_3 * V_4 , T_3 V_10 ,
unsigned V_54 , unsigned V_50 , unsigned V_51 ,
void * V_55 )
{
int (* F_57)( struct V_3 * V_4 , unsigned V_54 ,
unsigned V_50 , unsigned V_51 , T_3 V_10 ,
void * V_55 ) = NULL ;
switch ( V_54 ) {
case V_26 :
switch ( V_10 & V_67 ) {
case V_68 :
F_57 = F_49 ;
break;
case V_69 :
F_57 = F_47 ;
break;
case V_70 :
F_57 = F_50 ;
break;
}
break;
case V_42 :
case V_41 :
switch ( V_10 & V_67 ) {
case V_68 :
case V_69 :
break;
case V_70 :
F_57 = F_51 ;
break;
}
break;
case V_63 :
switch ( V_10 & V_67 ) {
case V_70 :
if ( F_58 ( V_4 -> V_9 ) )
F_57 = F_54 ;
break;
}
break;
case V_65 :
switch ( V_10 & V_67 ) {
case V_70 :
F_57 = F_55 ;
break;
}
break;
}
if ( ! F_57 )
return - V_59 ;
return F_57 ( V_4 , V_54 , V_50 , V_51 , V_10 , V_55 ) ;
}
