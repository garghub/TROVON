static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 , * V_7 ;
struct V_8 * * V_9 , * V_10 = NULL ;
V_6 = F_2 ( sizeof( struct V_5 ) , V_11 ) ;
if ( F_3 ( ! V_6 ) )
return - V_12 ;
V_6 -> V_3 = V_3 ;
V_6 -> V_4 = V_4 ;
V_9 = & V_2 -> V_6 . V_8 ;
while ( * V_9 ) {
V_10 = * V_9 ;
V_7 = F_4 ( V_10 , struct V_5 , V_13 ) ;
if ( V_3 < V_7 -> V_3 )
V_9 = & ( * V_9 ) -> V_14 ;
else if ( V_3 > V_7 -> V_3 )
V_9 = & ( * V_9 ) -> V_15 ;
else if ( V_4 < V_7 -> V_4 )
V_9 = & ( * V_9 ) -> V_14 ;
else if ( V_4 > V_7 -> V_4 )
V_9 = & ( * V_9 ) -> V_15 ;
else {
F_5 ( L_1 ) ;
F_6 ( V_6 ) ;
return 0 ;
}
}
F_7 ( & V_6 -> V_13 , V_10 , V_9 ) ;
F_8 ( & V_6 -> V_13 , & V_2 -> V_6 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
if ( V_17 -> V_10 ) {
struct V_18 * V_19 ;
V_19 = & V_17 -> V_10 -> V_20 [ V_17 -> V_21 ] ;
if ( V_19 -> V_22 )
return F_1 ( V_2 , V_19 -> V_3 , V_19 -> V_4 ) ;
} else
if ( V_2 -> V_23 . V_22 )
return F_1 ( V_2 , V_2 -> V_23 . V_3 ,
V_2 -> V_23 . V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
int V_24 ;
if ( V_17 -> V_10 ) {
struct V_18 * V_19 ;
V_19 = & V_17 -> V_10 -> V_20 [ V_17 -> V_21 ] ;
if ( V_19 -> V_22 ) {
V_24 = F_1 ( V_2 , V_19 -> V_3 , V_19 -> V_4 ) ;
if ( V_24 )
return V_24 ;
V_19 -> V_3 = 0 ;
V_19 -> V_4 = 0 ;
V_19 -> V_22 = 0 ;
}
} else
if ( V_2 -> V_23 . V_22 ) {
V_24 = F_1 ( V_2 , V_2 -> V_23 . V_3 , V_2 -> V_23 . V_4 ) ;
if ( V_24 )
return V_24 ;
V_2 -> V_23 . V_3 = 0 ;
V_2 -> V_23 . V_4 = 0 ;
V_2 -> V_23 . V_22 = 0 ;
}
return 0 ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_8 * V_25 = V_2 -> V_6 . V_8 ;
struct V_5 * V_6 ;
while ( V_25 ) {
if ( V_25 -> V_14 ) {
V_25 = V_25 -> V_14 ;
continue;
} else if ( V_25 -> V_15 ) {
V_25 = V_25 -> V_15 ;
continue;
}
V_6 = F_4 ( V_25 , struct V_5 , V_13 ) ;
V_25 = F_12 ( V_25 ) ;
if ( V_25 ) {
if ( V_25 -> V_14 == & V_6 -> V_13 )
V_25 -> V_14 = NULL ;
else
V_25 -> V_15 = NULL ;
}
F_6 ( V_6 ) ;
}
V_2 -> V_6 = V_26 ;
}
static struct V_16 * F_13 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_16 * V_27 ;
V_27 = F_2 ( V_2 -> V_28 , V_11 ) ;
if ( F_3 ( ! V_27 ) )
return F_14 ( - V_12 ) ;
memcpy ( V_27 , V_17 , V_2 -> V_28 ) ;
V_27 -> V_29 = NULL ;
F_15 ( V_30 , & V_27 -> V_31 ) ;
F_16 ( V_32 , & V_27 -> V_31 ) ;
F_17 ( ! F_18 ( V_17 ) ) ;
F_15 ( V_33 , & V_17 -> V_31 ) ;
if ( V_17 -> V_34 != 0 ) {
int V_35 ;
const int V_36 = V_27 -> V_37 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
struct V_18 * V_19 = & V_27 -> V_20 [ V_35 ] ;
if ( V_19 -> V_17 )
V_19 -> V_17 -> V_10 = V_27 ;
}
}
F_19 ( & V_2 -> V_38 ) ;
return V_27 ;
}
static int F_20 ( struct V_1 * V_2 , int V_3 , int V_39 )
{
V_2 -> V_40 -= F_21 ( V_39 , 8 ) ;
return F_22 ( V_2 , V_3 , V_39 ) ;
}
static struct V_16 * F_23 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_16 * V_17 = V_19 -> V_17 ;
struct V_16 * V_27 ;
int V_24 ;
if ( ! F_24 ( V_17 ) ) {
if ( ! F_25 ( V_30 , & V_17 -> V_31 ) ) {
F_19 ( & V_2 -> V_38 ) ;
F_26 ( & V_2 -> V_41 ) ;
F_26 ( & V_42 ) ;
V_24 = F_20 ( V_2 , V_19 -> V_3 , V_19 -> V_22 ) ;
if ( F_3 ( V_24 ) )
return F_14 ( V_24 ) ;
}
return V_17 ;
}
V_27 = F_13 ( V_2 , V_17 ) ;
if ( F_27 ( V_27 ) )
return V_27 ;
if ( V_19 -> V_22 ) {
V_24 = F_1 ( V_2 , V_19 -> V_3 , V_19 -> V_4 ) ;
if ( F_3 ( V_24 ) )
return F_14 ( V_24 ) ;
V_24 = F_20 ( V_2 , V_19 -> V_3 , V_19 -> V_22 ) ;
} else
V_24 = 0 ;
V_19 -> V_17 = V_27 ;
V_19 -> V_3 = 0 ;
V_19 -> V_4 = 0 ;
V_19 -> V_22 = 0 ;
if ( F_3 ( V_24 ) )
return F_14 ( V_24 ) ;
return V_27 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_18 * V_19 ,
const void * V_43 )
{
int V_24 ;
void * V_44 ;
const struct V_45 * V_46 = V_43 ;
F_17 ( ! V_19 -> V_47 ) ;
F_17 ( V_19 -> V_22 != 0 ) ;
F_17 ( F_29 ( V_2 , & V_19 -> V_48 ) ) ;
V_24 = F_30 ( V_2 , V_46 ) ;
if ( V_24 ) {
F_31 () ;
F_32 ( V_2 , V_46 ) ;
return V_24 ;
}
V_44 = F_2 ( V_19 -> V_22 , V_11 ) ;
if ( ! V_44 )
return 0 ;
memcpy ( V_44 , V_43 , V_19 -> V_22 ) ;
V_19 -> V_47 = V_44 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_18 * V_19 ,
void * V_43 )
{
int V_24 ;
F_17 ( ! V_19 -> V_47 ) ;
F_17 ( V_19 -> V_22 != 0 ) ;
V_24 = F_30 ( V_2 , V_43 ) ;
if ( V_24 ) {
F_31 () ;
F_32 ( V_2 , V_43 ) ;
return V_24 ;
}
V_19 -> V_47 = V_43 ;
return 0 ;
}
static void F_34 ( struct V_18 * V_19 )
{
if ( ! V_19 -> V_47 )
return;
F_6 ( V_19 -> V_47 ) ;
V_19 -> V_47 = NULL ;
}
static int F_35 ( struct V_1 * V_2 , struct V_18 * V_19 ,
void * V_43 )
{
int V_24 ;
F_17 ( F_29 ( V_2 , & V_19 -> V_48 ) ) ;
if ( V_19 -> V_47 ) {
F_17 ( V_19 -> V_22 != 0 ) ;
memcpy ( V_43 , V_19 -> V_47 , V_19 -> V_22 ) ;
return 0 ;
}
V_24 = F_36 ( V_2 , V_19 , V_43 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_28 ( V_2 , V_19 , V_43 ) ;
return V_24 ;
}
static int F_37 ( const struct V_1 * V_2 , void * V_49 , int type ,
int V_22 , int V_3 , int V_4 )
{
int V_24 , V_50 ;
struct V_51 * V_52 = V_49 ;
T_1 V_53 , V_54 ;
F_38 ( L_2 , V_3 , V_4 , F_39 ( type ) , V_22 ) ;
V_24 = F_40 ( V_2 , V_3 , V_49 , V_4 , V_22 , 1 ) ;
if ( V_24 ) {
F_5 ( L_3 ,
type , V_3 , V_4 , V_24 ) ;
return V_24 ;
}
if ( F_41 ( V_52 -> V_55 ) != V_56 )
return 0 ;
if ( V_52 -> V_57 != type )
return 0 ;
V_50 = F_41 ( V_52 -> V_22 ) ;
if ( V_50 != V_22 )
return 0 ;
if ( type == V_58 && V_2 -> V_59 && ! V_2 -> V_60 &&
! V_2 -> V_61 )
return 1 ;
V_53 = F_42 ( V_62 , V_49 + 8 , V_50 - 8 ) ;
V_54 = F_41 ( V_52 -> V_53 ) ;
if ( V_53 != V_54 )
return 0 ;
return 1 ;
}
static int F_43 ( struct V_1 * V_2 , const union V_63 * V_48 ,
struct V_18 * V_19 , void * V_43 )
{
int V_64 ;
F_44 ( L_4 , V_19 -> V_3 , V_19 -> V_4 , F_45 ( V_48 ) ) ;
V_64 = F_37 ( V_2 , V_43 , F_46 ( V_2 , V_48 ) , V_19 -> V_22 , V_19 -> V_3 ,
V_19 -> V_4 ) ;
if ( V_64 == 1 ) {
union V_63 V_65 ;
struct V_45 * V_46 = V_43 ;
F_47 ( V_2 , & V_46 -> V_48 , & V_65 ) ;
if ( F_48 ( V_2 , V_48 , & V_65 ) != 0 )
V_64 = 0 ;
}
if ( V_64 == 0 && V_2 -> V_66 )
F_49 ( L_5 ,
V_19 -> V_3 , V_19 -> V_4 , V_19 -> V_22 , F_45 ( V_48 ) ) ;
return V_64 ;
}
static int F_50 ( struct V_1 * V_2 , struct V_18 * V_19 ,
const struct V_67 * V_68 )
{
struct V_45 * V_46 ;
int V_69 , V_24 ;
if ( ! V_19 -> V_47 ) {
V_46 = F_2 ( V_19 -> V_22 , V_11 ) ;
if ( ! V_46 )
return - V_12 ;
V_24 = F_36 ( V_2 , V_19 , V_46 ) ;
if ( V_24 )
goto V_70;
V_24 = F_33 ( V_2 , V_19 , V_46 ) ;
if ( V_24 )
goto V_70;
} else
V_46 = V_19 -> V_47 ;
V_69 = F_51 ( V_46 -> V_69 ) ;
V_24 = memcmp ( V_46 -> V_71 , V_68 -> V_71 , F_52 ( int , V_69 , V_68 -> V_22 ) ) ;
if ( V_24 == 0 ) {
if ( V_69 == V_68 -> V_22 )
return V_72 ;
else if ( V_69 < V_68 -> V_22 )
return V_73 ;
else
return V_74 ;
} else if ( V_24 < 0 )
return V_73 ;
else
return V_74 ;
V_70:
F_6 ( V_46 ) ;
return V_24 ;
}
static struct V_16 * F_53 ( struct V_1 * V_2 ,
struct V_16 * V_17 , int V_36 )
{
struct V_18 * V_19 ;
V_19 = & V_17 -> V_20 [ V_36 ] ;
if ( V_19 -> V_17 )
V_17 = V_19 -> V_17 ;
else
V_17 = F_54 ( V_2 , V_19 , V_17 , V_36 ) ;
return V_17 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_16 * * V_27 , int * V_36 )
{
struct V_16 * V_17 = * V_27 ;
int V_75 = * V_36 ;
V_75 += 1 ;
if ( V_75 < V_17 -> V_37 ) {
* V_36 = V_75 ;
return 0 ;
}
while ( 1 ) {
struct V_16 * V_76 ;
V_76 = V_17 -> V_10 ;
if ( ! V_76 )
return - V_77 ;
V_75 = V_17 -> V_21 + 1 ;
V_17 = V_76 ;
if ( V_75 < V_17 -> V_37 ) {
V_17 = F_53 ( V_2 , V_17 , V_75 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
while ( V_17 -> V_34 != 0 ) {
V_17 = F_53 ( V_2 , V_17 , 0 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
}
V_75 = 0 ;
break;
}
}
* V_27 = V_17 ;
* V_36 = V_75 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_16 * * V_27 , int * V_36 )
{
struct V_16 * V_17 = * V_27 ;
int V_75 = * V_36 ;
if ( V_75 > 0 ) {
* V_36 = V_75 - 1 ;
return 0 ;
}
while ( 1 ) {
struct V_16 * V_76 ;
V_76 = V_17 -> V_10 ;
if ( ! V_76 )
return - V_77 ;
V_75 = V_17 -> V_21 - 1 ;
V_17 = V_76 ;
if ( V_75 >= 0 ) {
V_17 = F_53 ( V_2 , V_17 , V_75 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
while ( V_17 -> V_34 != 0 ) {
V_75 = V_17 -> V_37 - 1 ;
V_17 = F_53 ( V_2 , V_17 , V_75 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
}
V_75 = V_17 -> V_37 - 1 ;
break;
}
}
* V_27 = V_17 ;
* V_36 = V_75 ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , const union V_63 * V_48 ,
struct V_16 * * V_27 , int * V_36 ,
const struct V_67 * V_68 )
{
int V_24 ;
V_24 = F_50 ( V_2 , & ( * V_27 ) -> V_20 [ * V_36 ] , V_68 ) ;
if ( F_3 ( V_24 < 0 ) )
return V_24 ;
if ( V_24 == V_72 )
return 1 ;
if ( V_24 == V_74 ) {
while ( 1 ) {
V_24 = F_57 ( V_2 , V_27 , V_36 ) ;
if ( V_24 == - V_77 ) {
F_17 ( * V_36 == 0 ) ;
* V_36 = - 1 ;
return 0 ;
}
if ( V_24 < 0 )
return V_24 ;
if ( F_48 ( V_2 , & ( * V_27 ) -> V_20 [ * V_36 ] . V_48 , V_48 ) ) {
if ( * V_36 == ( * V_27 ) -> V_37 - 1 ) {
V_24 = F_55 ( V_2 , V_27 , V_36 ) ;
if ( V_24 ) {
F_17 ( 0 ) ;
if ( V_24 == - V_77 )
V_24 = - V_78 ;
return V_24 ;
}
F_17 ( * V_36 == 0 ) ;
* V_36 = - 1 ;
}
return 0 ;
}
V_24 = F_50 ( V_2 , & ( * V_27 ) -> V_20 [ * V_36 ] , V_68 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_24 == V_73 )
return 0 ;
if ( V_24 == V_72 )
return 1 ;
F_17 ( V_24 == V_74 ) ;
}
} else {
int V_75 = * V_36 ;
struct V_16 * V_17 = * V_27 ;
while ( 1 ) {
V_24 = F_55 ( V_2 , & V_17 , & V_75 ) ;
if ( V_24 == - V_77 )
return 0 ;
if ( V_24 < 0 )
return V_24 ;
if ( F_48 ( V_2 , & V_17 -> V_20 [ V_75 ] . V_48 , V_48 ) )
return 0 ;
V_24 = F_50 ( V_2 , & V_17 -> V_20 [ V_75 ] , V_68 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_24 == V_74 )
return 0 ;
* V_27 = V_17 ;
* V_36 = V_75 ;
if ( V_24 == V_72 )
return 1 ;
F_17 ( V_24 == V_73 ) ;
}
}
}
static int F_59 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
const struct V_67 * V_68 )
{
struct V_45 * V_46 ;
int V_69 , V_24 ;
if ( ! V_19 -> V_47 ) {
V_46 = F_2 ( V_19 -> V_22 , V_11 ) ;
if ( ! V_46 )
return - V_12 ;
V_24 = F_43 ( V_2 , & V_19 -> V_48 , V_19 , V_46 ) ;
if ( V_24 < 0 )
goto V_70;
if ( V_24 == 0 ) {
V_24 = V_79 ;
goto V_70;
}
F_17 ( V_24 == 1 ) ;
V_24 = F_33 ( V_2 , V_19 , V_46 ) ;
if ( V_24 )
goto V_70;
} else
V_46 = V_19 -> V_47 ;
V_69 = F_51 ( V_46 -> V_69 ) ;
V_24 = memcmp ( V_46 -> V_71 , V_68 -> V_71 , F_52 ( int , V_69 , V_68 -> V_22 ) ) ;
if ( V_24 == 0 ) {
if ( V_69 == V_68 -> V_22 )
return V_72 ;
else if ( V_69 < V_68 -> V_22 )
return V_73 ;
else
return V_74 ;
} else if ( V_24 < 0 )
return V_73 ;
else
return V_74 ;
V_70:
F_6 ( V_46 ) ;
return V_24 ;
}
static int F_60 ( struct V_1 * V_2 ,
const union V_63 * V_48 ,
struct V_16 * * V_27 , int * V_36 ,
const struct V_67 * V_68 , int V_80 )
{
struct V_16 * V_81 = NULL , * V_17 = * V_27 ;
int V_82 ( V_83 ) , V_24 , V_84 , V_85 = 0 , V_75 = * V_36 ;
V_84 = F_59 ( V_2 , & V_17 -> V_20 [ V_75 ] , V_68 ) ;
if ( F_3 ( V_84 < 0 ) )
return V_84 ;
if ( V_84 == V_72 )
return 1 ;
if ( V_84 == V_79 ) {
V_81 = V_17 ;
V_83 = V_75 ;
V_85 = 1 ;
} else if ( ! V_80 )
V_85 = 1 ;
if ( V_84 == V_74 || V_85 ) {
while ( 1 ) {
V_24 = F_57 ( V_2 , V_27 , V_36 ) ;
if ( V_24 == - V_77 ) {
F_17 ( * V_36 == 0 ) ;
* V_36 = - 1 ;
break;
}
if ( V_24 < 0 )
return V_24 ;
if ( F_48 ( V_2 , & ( * V_27 ) -> V_20 [ * V_36 ] . V_48 , V_48 ) ) {
if ( * V_36 == ( * V_27 ) -> V_37 - 1 ) {
V_24 = F_55 ( V_2 , V_27 , V_36 ) ;
if ( V_24 ) {
F_17 ( 0 ) ;
if ( V_24 == - V_77 )
V_24 = - V_78 ;
return V_24 ;
}
F_17 ( * V_36 == 0 ) ;
* V_36 = - 1 ;
}
break;
}
V_24 = F_59 ( V_2 , & ( * V_27 ) -> V_20 [ * V_36 ] , V_68 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_24 == V_72 )
return 1 ;
if ( V_24 == V_79 ) {
V_81 = * V_27 ;
V_83 = * V_36 ;
continue;
}
if ( ! V_80 )
continue;
if ( V_24 == V_73 )
break;
else
V_85 = 0 ;
}
}
if ( V_84 == V_73 || V_85 ) {
* V_27 = V_17 ;
* V_36 = V_75 ;
while ( 1 ) {
V_24 = F_55 ( V_2 , & V_17 , & V_75 ) ;
if ( V_24 == - V_77 )
break;
if ( V_24 < 0 )
return V_24 ;
if ( F_48 ( V_2 , & V_17 -> V_20 [ V_75 ] . V_48 , V_48 ) )
break;
V_24 = F_59 ( V_2 , & V_17 -> V_20 [ V_75 ] , V_68 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_24 == V_74 )
break;
* V_27 = V_17 ;
* V_36 = V_75 ;
if ( V_24 == V_72 )
return 1 ;
if ( V_24 == V_79 ) {
V_81 = V_17 ;
V_83 = V_75 ;
}
}
}
if ( V_80 || ! V_81 )
return 0 ;
F_49 ( L_6 ,
V_81 -> V_20 [ V_83 ] . V_3 , V_81 -> V_20 [ V_83 ] . V_4 ,
V_81 -> V_20 [ V_83 ] . V_22 , F_45 ( V_48 ) ) ;
* V_27 = V_81 ;
* V_36 = V_83 ;
return 1 ;
}
static int F_61 ( struct V_18 * V_19 , int V_3 , int V_4 )
{
if ( V_19 -> V_3 == V_3 && V_19 -> V_4 == V_4 )
return 1 ;
else
return 0 ;
}
static int F_62 ( struct V_1 * V_2 ,
const union V_63 * V_48 ,
struct V_16 * * V_27 , int * V_36 ,
int V_3 , int V_4 )
{
struct V_16 * V_17 ;
int V_75 , V_24 ;
V_17 = * V_27 ;
V_75 = * V_36 ;
if ( F_61 ( & V_17 -> V_20 [ V_75 ] , V_3 , V_4 ) )
return 1 ;
while ( 1 ) {
V_24 = F_57 ( V_2 , & V_17 , & V_75 ) ;
if ( V_24 == - V_77 )
break;
if ( V_24 < 0 )
return V_24 ;
if ( F_48 ( V_2 , & V_17 -> V_20 [ V_75 ] . V_48 , V_48 ) )
break;
if ( F_61 ( & V_17 -> V_20 [ V_75 ] , V_3 , V_4 ) ) {
* V_27 = V_17 ;
* V_36 = V_75 ;
return 1 ;
}
}
V_17 = * V_27 ;
V_75 = * V_36 ;
while ( 1 ) {
V_24 = F_55 ( V_2 , & V_17 , & V_75 ) ;
if ( V_24 == - V_77 )
return 0 ;
if ( V_24 < 0 )
return V_24 ;
if ( F_48 ( V_2 , & V_17 -> V_20 [ V_75 ] . V_48 , V_48 ) )
return 0 ;
* V_27 = V_17 ;
* V_36 = V_75 ;
if ( F_61 ( & V_17 -> V_20 [ V_75 ] , V_3 , V_4 ) )
return 1 ;
}
}
static struct V_16 * F_63 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_16 * V_76 ;
int * V_86 = V_2 -> V_87 , V_9 = 0 ;
F_17 ( V_2 -> V_23 . V_17 ) ;
F_17 ( V_17 ) ;
if ( V_2 -> V_23 . V_17 -> V_34 > V_88 ) {
F_6 ( V_2 -> V_87 ) ;
V_2 -> V_87 = F_2 ( V_2 -> V_23 . V_17 -> V_34 * sizeof( int ) ,
V_11 ) ;
if ( ! V_2 -> V_87 )
return F_14 ( - V_12 ) ;
V_86 = V_2 -> V_87 ;
}
if ( V_2 -> V_23 . V_17 -> V_34 ) {
while ( 1 ) {
int V_36 ;
V_76 = V_17 -> V_10 ;
if ( ! V_76 )
break;
V_36 = V_17 -> V_21 ;
F_17 ( V_9 < V_2 -> V_23 . V_17 -> V_34 ) ;
V_86 [ V_9 ++ ] = V_36 ;
if ( ! V_76 -> V_29 && F_64 ( V_17 ) )
break;
V_17 = V_76 ;
}
}
while ( 1 ) {
struct V_18 * V_19 ;
V_76 = V_17 -> V_10 ;
if ( V_76 ) {
F_17 ( V_86 [ V_9 - 1 ] >= 0 ) ;
F_17 ( V_86 [ V_9 - 1 ] < V_76 -> V_37 ) ;
V_19 = & V_76 -> V_20 [ V_86 [ -- V_9 ] ] ;
V_17 = F_23 ( V_2 , V_19 ) ;
} else {
F_17 ( V_17 == V_2 -> V_23 . V_17 ) ;
V_17 = F_23 ( V_2 , & V_2 -> V_23 ) ;
}
if ( F_27 ( V_17 ) || ! V_9 )
break;
F_17 ( V_86 [ V_9 - 1 ] >= 0 ) ;
F_17 ( V_86 [ V_9 - 1 ] < V_17 -> V_37 ) ;
V_17 = V_17 -> V_20 [ V_86 [ V_9 - 1 ] ] . V_17 ;
}
return V_17 ;
}
int F_65 ( struct V_1 * V_2 , const union V_63 * V_48 ,
struct V_16 * * V_27 , int * V_36 )
{
int V_24 , V_89 ;
struct V_16 * V_17 ;
unsigned long time = F_66 () ;
F_44 ( L_7 , F_45 ( V_48 ) ) ;
F_17 ( F_46 ( V_2 , V_48 ) < V_90 ) ;
V_17 = V_2 -> V_23 . V_17 ;
if ( F_3 ( ! V_17 ) ) {
V_17 = F_54 ( V_2 , & V_2 -> V_23 , NULL , 0 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
}
V_17 -> time = time ;
while ( 1 ) {
struct V_18 * V_19 ;
V_89 = F_67 ( V_2 , V_17 , V_48 , V_36 ) ;
if ( V_17 -> V_34 == 0 )
break;
if ( * V_36 < 0 )
* V_36 = 0 ;
V_19 = & V_17 -> V_20 [ * V_36 ] ;
if ( V_19 -> V_17 ) {
V_17 -> time = time ;
V_17 = V_19 -> V_17 ;
continue;
}
V_17 = F_54 ( V_2 , V_19 , V_17 , * V_36 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
}
* V_27 = V_17 ;
if ( V_89 || ! F_29 ( V_2 , V_48 ) || * V_36 != - 1 ) {
F_44 ( L_8 , V_89 , V_17 -> V_34 , * V_36 ) ;
return V_89 ;
}
V_24 = F_57 ( V_2 , & V_17 , V_36 ) ;
if ( V_24 == - V_77 ) {
F_44 ( L_9 , V_17 -> V_34 ) ;
* V_36 = - 1 ;
return 0 ;
}
if ( F_3 ( V_24 < 0 ) )
return V_24 ;
if ( F_48 ( V_2 , V_48 , & V_17 -> V_20 [ * V_36 ] . V_48 ) ) {
F_44 ( L_9 , V_17 -> V_34 ) ;
* V_36 = - 1 ;
return 0 ;
}
F_44 ( L_10 , V_17 -> V_34 , * V_36 ) ;
* V_27 = V_17 ;
return 1 ;
}
static int F_68 ( struct V_1 * V_2 , const union V_63 * V_48 ,
struct V_16 * * V_27 , int * V_36 )
{
int V_24 , V_89 ;
struct V_16 * V_17 ;
unsigned long time = F_66 () ;
F_44 ( L_11 , F_45 ( V_48 ) ) ;
V_17 = V_2 -> V_23 . V_17 ;
if ( F_3 ( ! V_17 ) ) {
V_17 = F_54 ( V_2 , & V_2 -> V_23 , NULL , 0 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
}
V_17 = F_23 ( V_2 , & V_2 -> V_23 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
V_17 -> time = time ;
while ( 1 ) {
struct V_18 * V_19 ;
V_89 = F_67 ( V_2 , V_17 , V_48 , V_36 ) ;
if ( V_17 -> V_34 == 0 )
break;
if ( * V_36 < 0 )
* V_36 = 0 ;
V_19 = & V_17 -> V_20 [ * V_36 ] ;
if ( V_19 -> V_17 ) {
V_17 -> time = time ;
V_17 = F_23 ( V_2 , V_19 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
continue;
}
V_17 = F_54 ( V_2 , V_19 , V_17 , * V_36 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
V_17 = F_23 ( V_2 , V_19 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
}
* V_27 = V_17 ;
if ( V_89 || ! F_29 ( V_2 , V_48 ) || * V_36 != - 1 ) {
F_44 ( L_8 , V_89 , V_17 -> V_34 , * V_36 ) ;
return V_89 ;
}
V_24 = F_57 ( V_2 , & V_17 , V_36 ) ;
if ( V_24 == - V_77 ) {
* V_36 = - 1 ;
F_44 ( L_9 , V_17 -> V_34 ) ;
return 0 ;
}
if ( F_3 ( V_24 < 0 ) )
return V_24 ;
if ( F_48 ( V_2 , V_48 , & V_17 -> V_20 [ * V_36 ] . V_48 ) ) {
* V_36 = - 1 ;
F_44 ( L_9 , V_17 -> V_34 ) ;
return 0 ;
}
if ( V_17 -> V_29 || ! F_64 ( V_17 ) ) {
V_17 = F_63 ( V_2 , V_17 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
}
F_44 ( L_10 , V_17 -> V_34 , * V_36 ) ;
* V_27 = V_17 ;
return 1 ;
}
static int F_69 ( struct V_1 * V_2 , int V_3 , int V_91 )
{
int V_92 , V_93 ;
V_93 = V_2 -> V_93 ;
F_70 () ;
V_92 = V_2 -> V_94 ;
if ( V_91 == V_92 )
return 0 ;
if ( V_91 + 1 != V_92 )
return 1 ;
F_70 () ;
if ( V_93 != V_2 -> V_93 )
return 1 ;
if ( V_93 == V_3 )
return 1 ;
return 0 ;
}
int F_71 ( struct V_1 * V_2 , const union V_63 * V_48 ,
void * V_43 , int * V_3 , int * V_4 )
{
int V_95 , V_36 , V_24 , V_96 = 0 , V_91 ;
struct V_16 * V_17 ;
struct V_18 V_19 , * V_97 ;
V_98:
F_72 ( & V_2 -> V_99 ) ;
V_95 = F_65 ( V_2 , V_48 , & V_17 , & V_36 ) ;
if ( ! V_95 ) {
V_24 = - V_77 ;
goto V_100;
} else if ( V_95 < 0 ) {
V_24 = V_95 ;
goto V_100;
}
V_97 = & V_17 -> V_20 [ V_36 ] ;
if ( V_3 ) {
* V_3 = V_97 -> V_3 ;
* V_4 = V_97 -> V_4 ;
}
if ( F_29 ( V_2 , V_48 ) ) {
V_24 = F_35 ( V_2 , V_97 , V_43 ) ;
goto V_100;
}
if ( V_96 ) {
V_24 = F_36 ( V_2 , V_97 , V_43 ) ;
goto V_100;
}
V_19 = V_17 -> V_20 [ V_36 ] ;
V_91 = V_2 -> V_94 ;
F_73 ( & V_2 -> V_99 ) ;
if ( F_74 ( V_2 , V_19 . V_3 ) ) {
V_24 = F_36 ( V_2 , & V_19 , V_43 ) ;
return V_24 ;
}
V_24 = F_43 ( V_2 , V_48 , & V_19 , V_43 ) ;
if ( V_24 <= 0 || F_69 ( V_2 , V_19 . V_3 , V_91 ) ) {
V_96 = 1 ;
goto V_98;
}
return 0 ;
V_100:
F_73 ( & V_2 -> V_99 ) ;
return V_24 ;
}
int F_75 ( struct V_1 * V_2 , struct V_101 * V_102 )
{
int V_36 , V_24 = 0 , V_3 = - 1 , V_82 ( V_4 ) ;
int V_82 ( V_22 ) ;
unsigned int V_103 = F_76 ( V_2 , & V_102 -> V_48 ) ;
struct V_16 * V_17 ;
V_102 -> V_104 = 0 ;
V_102 -> V_105 = 0 ;
V_102 -> V_106 = 0 ;
F_72 ( & V_2 -> V_99 ) ;
V_24 = F_65 ( V_2 , & V_102 -> V_48 , & V_17 , & V_36 ) ;
if ( V_24 < 0 )
goto V_100;
if ( V_24 ) {
V_22 = V_17 -> V_20 [ V_36 ] . V_22 ;
if ( V_22 > V_102 -> V_107 ) {
V_24 = - V_78 ;
goto V_100;
}
V_102 -> V_20 [ V_102 -> V_104 ++ ] = V_17 -> V_20 [ V_36 ] ;
V_102 -> V_105 += 1 ;
V_3 = V_17 -> V_20 [ V_36 ] . V_3 ;
V_4 = F_21 ( V_17 -> V_20 [ V_36 ] . V_4 + V_22 , 8 ) ;
}
while ( 1 ) {
struct V_18 * V_19 ;
union V_63 * V_48 ;
unsigned int V_108 ;
V_24 = F_55 ( V_2 , & V_17 , & V_36 ) ;
if ( V_24 )
goto V_100;
V_19 = & V_17 -> V_20 [ V_36 ] ;
V_48 = & V_19 -> V_48 ;
if ( F_77 ( V_2 , V_48 ) != F_77 ( V_2 , & V_102 -> V_48 ) ||
F_46 ( V_2 , V_48 ) != V_109 ) {
V_24 = - V_77 ;
goto V_100;
}
if ( V_3 < 0 ) {
V_3 = V_19 -> V_3 ;
V_4 = F_21 ( V_19 -> V_4 + V_19 -> V_22 , 8 ) ;
V_22 = V_19 -> V_22 ;
if ( V_22 > V_102 -> V_107 ) {
V_24 = - V_78 ;
goto V_100;
}
} else {
if ( V_19 -> V_3 != V_3 || V_19 -> V_4 != V_4 )
goto V_100;
V_4 += F_21 ( V_19 -> V_22 , 8 ) ;
V_22 = F_21 ( V_22 , 8 ) + V_19 -> V_22 ;
if ( V_22 > V_102 -> V_107 )
goto V_100;
}
V_108 = F_76 ( V_2 , V_48 ) ;
V_102 -> V_105 += ( V_108 - V_103 - 1 ) ;
if ( V_102 -> V_105 >= V_110 )
goto V_100;
V_103 = V_108 ;
V_102 -> V_20 [ V_102 -> V_104 ++ ] = * V_19 ;
V_102 -> V_105 += 1 ;
if ( V_102 -> V_104 >= V_110 )
goto V_100;
if ( V_102 -> V_105 >= V_110 )
goto V_100;
}
V_100:
if ( V_24 == - V_77 ) {
V_102 -> V_106 = 1 ;
V_24 = 0 ;
}
V_102 -> V_94 = V_2 -> V_94 ;
F_73 ( & V_2 -> V_99 ) ;
if ( V_24 )
return V_24 ;
if ( V_102 -> V_105 > V_110 )
V_102 -> V_105 = V_110 ;
if ( V_111 == 1 ||
! ( V_102 -> V_105 & ( V_111 - 1 ) ) )
return 0 ;
if ( V_102 -> V_106 ) {
V_102 -> V_105 += V_111 - 1 ;
return 0 ;
}
V_103 = F_76 ( V_2 , & V_102 -> V_48 ) + V_102 -> V_105 ;
V_103 &= ~ ( V_111 - 1 ) ;
while ( V_102 -> V_104 ) {
if ( F_76 ( V_2 , & V_102 -> V_20 [ V_102 -> V_104 - 1 ] . V_48 ) < V_103 )
break;
V_102 -> V_104 -= 1 ;
}
return 0 ;
}
static int F_78 ( struct V_112 * V_113 , void * V_49 , int V_22 , int V_3 ,
int V_4 )
{
const struct V_1 * V_2 = V_113 -> V_2 ;
int V_114 , V_115 ;
F_38 ( L_12 , V_3 , V_4 , V_22 ) ;
F_17 ( V_113 && V_3 >= 0 && V_3 < V_2 -> V_116 && V_4 >= 0 ) ;
F_17 ( ! ( V_4 & 7 ) && V_4 < V_2 -> V_117 ) ;
F_17 ( V_4 + V_22 <= V_2 -> V_117 ) ;
F_79 ( & V_113 -> V_118 ) ;
V_115 = ( V_3 == V_113 -> V_3 && V_4 + V_22 > V_113 -> V_4 ) ;
if ( ! V_115 ) {
F_80 ( & V_113 -> V_118 ) ;
return F_40 ( V_2 , V_3 , V_49 , V_4 , V_22 , 0 ) ;
}
V_114 = V_113 -> V_4 - V_4 ;
if ( V_114 < 0 )
V_114 = 0 ;
memcpy ( V_49 + V_114 , V_113 -> V_49 + V_4 + V_114 - V_113 -> V_4 , V_22 - V_114 ) ;
F_80 ( & V_113 -> V_118 ) ;
if ( V_114 > 0 )
return F_40 ( V_2 , V_3 , V_49 , V_4 , V_114 , 0 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , void * V_49 ,
struct V_18 * V_19 )
{
union V_63 V_119 ;
struct V_51 * V_52 = V_49 ;
int V_24 , V_22 ;
if ( V_52 -> V_57 != V_58 ) {
F_5 ( L_13 ,
V_52 -> V_57 , V_58 ) ;
goto V_120;
}
V_24 = F_82 ( V_2 , V_49 , V_19 -> V_3 , V_19 -> V_4 , 0 , 0 ) ;
if ( V_24 ) {
F_5 ( L_14 , V_58 ) ;
goto V_100;
}
V_22 = F_41 ( V_52 -> V_22 ) ;
if ( V_22 != V_19 -> V_22 ) {
F_5 ( L_15 , V_22 , V_19 -> V_22 ) ;
goto V_120;
}
F_47 ( V_2 , V_49 + V_121 , & V_119 ) ;
if ( ! F_83 ( V_2 , & V_19 -> V_48 , & V_119 ) ) {
F_5 ( L_16 ,
V_19 -> V_3 , V_19 -> V_4 ) ;
F_44 ( L_17 ,
F_45 ( & V_19 -> V_48 ) , F_84 ( & V_119 ) ) ;
goto V_120;
}
return 0 ;
V_120:
V_24 = - V_78 ;
V_100:
F_5 ( L_18 , V_19 -> V_3 , V_19 -> V_4 ) ;
F_32 ( V_2 , V_49 ) ;
F_31 () ;
return V_24 ;
}
int F_85 ( struct V_1 * V_2 , struct V_101 * V_102 )
{
int V_3 = V_102 -> V_20 [ 0 ] . V_3 , V_4 = V_102 -> V_20 [ 0 ] . V_4 , V_22 , V_24 , V_35 ;
struct V_112 * V_113 ;
void * V_49 ;
V_22 = V_102 -> V_20 [ V_102 -> V_104 - 1 ] . V_4 ;
V_22 += V_102 -> V_20 [ V_102 -> V_104 - 1 ] . V_22 - V_4 ;
if ( V_22 > V_102 -> V_107 ) {
F_5 ( L_19 , V_102 -> V_107 , V_22 ) ;
return - V_78 ;
}
V_113 = F_74 ( V_2 , V_3 ) ;
if ( V_113 )
V_24 = F_78 ( V_113 , V_102 -> V_49 , V_22 , V_3 , V_4 ) ;
else
V_24 = F_40 ( V_2 , V_3 , V_102 -> V_49 , V_4 , V_22 , 0 ) ;
if ( F_69 ( V_2 , V_3 , V_102 -> V_94 ) )
return - V_122 ;
if ( V_24 && V_24 != - V_123 ) {
F_5 ( L_20 ,
V_3 , V_4 , V_24 ) ;
F_31 () ;
F_44 ( L_21 , F_45 ( & V_102 -> V_48 ) ) ;
return V_24 ;
}
V_49 = V_102 -> V_49 ;
for ( V_35 = 0 ; V_35 < V_102 -> V_104 ; V_35 ++ ) {
V_24 = F_81 ( V_2 , V_49 , & V_102 -> V_20 [ V_35 ] ) ;
if ( V_24 )
return V_24 ;
V_49 = V_49 + F_21 ( V_102 -> V_20 [ V_35 ] . V_22 , 8 ) ;
}
return 0 ;
}
static int F_86 ( struct V_1 * V_2 , const union V_63 * V_48 ,
void * V_43 , const struct V_67 * V_68 )
{
int V_95 , V_36 , V_24 ;
struct V_16 * V_17 ;
F_44 ( L_22 , V_68 -> V_22 , V_68 -> V_71 , F_45 ( V_48 ) ) ;
F_72 ( & V_2 -> V_99 ) ;
V_95 = F_65 ( V_2 , V_48 , & V_17 , & V_36 ) ;
if ( ! V_95 ) {
V_24 = - V_77 ;
goto V_124;
} else if ( V_95 < 0 ) {
V_24 = V_95 ;
goto V_124;
}
F_17 ( V_36 >= 0 ) ;
V_24 = F_58 ( V_2 , V_48 , & V_17 , & V_36 , V_68 ) ;
F_44 ( L_23 , V_24 , V_17 , V_36 ) ;
if ( F_3 ( V_24 < 0 ) )
goto V_124;
if ( V_24 == 0 ) {
V_24 = - V_77 ;
goto V_124;
}
V_24 = F_35 ( V_2 , & V_17 -> V_20 [ V_36 ] , V_43 ) ;
V_124:
F_73 ( & V_2 -> V_99 ) ;
return V_24 ;
}
int F_87 ( struct V_1 * V_2 , const union V_63 * V_48 ,
void * V_43 , const struct V_67 * V_68 )
{
int V_24 , V_22 ;
const struct V_45 * V_46 = V_43 ;
V_24 = F_88 ( V_2 , V_48 , V_43 ) ;
if ( V_24 )
return V_24 ;
V_22 = F_51 ( V_46 -> V_69 ) ;
if ( V_68 -> V_22 == V_22 && ! memcmp ( V_46 -> V_71 , V_68 -> V_71 , V_22 ) )
return 0 ;
return F_86 ( V_2 , V_48 , V_43 , V_68 ) ;
}
static void F_89 ( const struct V_1 * V_2 ,
struct V_16 * V_17 )
{
union V_63 * V_48 , * V_119 ;
F_17 ( V_17 -> V_10 ) ;
F_17 ( V_17 -> V_21 == 0 ) ;
V_48 = & V_17 -> V_20 [ 0 ] . V_48 ;
V_119 = & V_17 -> V_10 -> V_20 [ 0 ] . V_48 ;
while ( F_48 ( V_2 , V_48 , V_119 ) < 0 ) {
F_90 ( V_2 , V_48 , V_119 ) ;
V_17 = V_17 -> V_10 ;
V_17 -> V_125 = 1 ;
if ( ! V_17 -> V_10 || V_17 -> V_21 )
break;
V_119 = & V_17 -> V_10 -> V_20 [ 0 ] . V_48 ;
}
}
static void F_91 ( struct V_16 * V_17 ,
const struct V_18 * V_19 , int V_36 )
{
int V_35 ;
F_17 ( F_64 ( V_17 ) ) ;
if ( V_17 -> V_34 ) {
for ( V_35 = V_17 -> V_37 ; V_35 > V_36 ; V_35 -- ) {
V_17 -> V_20 [ V_35 ] = V_17 -> V_20 [ V_35 - 1 ] ;
if ( V_17 -> V_20 [ V_35 ] . V_17 )
V_17 -> V_20 [ V_35 ] . V_17 -> V_21 = V_35 ;
}
if ( V_19 -> V_17 )
V_19 -> V_17 -> V_21 = V_36 ;
} else
for ( V_35 = V_17 -> V_37 ; V_35 > V_36 ; V_35 -- )
V_17 -> V_20 [ V_35 ] = V_17 -> V_20 [ V_35 - 1 ] ;
V_17 -> V_20 [ V_36 ] = * V_19 ;
V_17 -> V_37 += 1 ;
if ( V_36 == 0 )
V_17 -> V_125 = 1 ;
}
static int F_92 ( struct V_1 * V_2 , struct V_16 * V_17 ,
struct V_18 * V_19 , int V_36 )
{
struct V_16 * V_27 , * V_126 , * V_76 ;
int V_35 , V_127 , V_128 , V_129 = 0 ;
union V_63 * V_48 = & V_19 -> V_48 , * V_119 ;
F_17 ( V_36 >= 0 && V_36 <= V_2 -> V_130 ) ;
V_98:
V_76 = V_17 -> V_10 ;
if ( V_17 -> V_37 < V_2 -> V_130 ) {
F_17 ( V_36 != V_2 -> V_130 ) ;
F_44 ( L_24 , V_36 , V_17 -> V_34 ,
F_45 ( V_48 ) ) ;
F_91 ( V_17 , V_19 , V_36 ) ;
if ( V_36 == 0 && V_76 && V_17 -> V_21 == 0 )
F_89 ( V_2 , V_17 ) ;
return 0 ;
}
F_44 ( L_25 , V_17 -> V_34 , F_45 ( V_48 ) ) ;
if ( V_17 -> V_125 )
F_10 ( V_2 , V_17 ) ;
V_27 = F_93 ( V_2 -> V_28 , V_11 ) ;
if ( ! V_27 )
return - V_12 ;
V_27 -> V_10 = V_76 ;
V_27 -> V_34 = V_17 -> V_34 ;
if ( V_17 -> V_34 == 0 && F_46 ( V_2 , V_48 ) == V_109 ) {
if ( V_36 == V_2 -> V_130 ) {
V_119 = & V_17 -> V_20 [ V_36 - 1 ] . V_48 ;
if ( F_77 ( V_2 , V_119 ) == F_77 ( V_2 , V_48 ) &&
F_46 ( V_2 , V_119 ) == V_109 )
V_129 = 1 ;
} else
goto V_131;
} else if ( V_129 && V_36 != V_2 -> V_130 ) {
V_129 = 0 ;
V_131:
if ( V_36 >= ( V_2 -> V_130 + 1 ) / 2 ) {
V_119 = & V_17 -> V_20 [ 0 ] . V_48 ;
if ( F_77 ( V_2 , V_119 ) == F_77 ( V_2 , V_48 ) &&
F_46 ( V_2 , V_119 ) == V_109 ) {
V_119 = & V_17 -> V_20 [ V_36 ] . V_48 ;
if ( F_77 ( V_2 , V_119 ) != F_77 ( V_2 , V_48 ) ||
F_46 ( V_2 , V_119 ) != V_109 ) {
V_127 = V_36 ;
V_128 = V_2 -> V_130 - V_127 ;
V_126 = V_17 ;
goto V_132;
}
}
}
}
if ( V_129 ) {
V_127 = V_2 -> V_130 ;
V_128 = 0 ;
} else {
V_127 = ( V_2 -> V_130 + 1 ) / 2 ;
V_128 = V_2 -> V_130 - V_127 ;
}
if ( V_36 < V_127 ) {
V_126 = V_17 ;
V_128 += 1 ;
V_127 -= 1 ;
} else {
V_126 = V_27 ;
V_36 -= V_127 ;
if ( V_27 -> V_34 != 0 )
V_19 -> V_17 -> V_10 = V_27 ;
}
V_132:
F_15 ( V_30 , & V_27 -> V_31 ) ;
F_19 ( & V_2 -> V_38 ) ;
V_27 -> V_37 = V_128 ;
V_17 -> V_37 = V_127 ;
F_44 ( L_26 , V_128 , V_127 ) ;
for ( V_35 = 0 ; V_35 < V_128 ; V_35 ++ ) {
V_27 -> V_20 [ V_35 ] = V_17 -> V_20 [ V_127 + V_35 ] ;
if ( V_27 -> V_34 != 0 )
if ( V_27 -> V_20 [ V_35 ] . V_17 ) {
V_27 -> V_20 [ V_35 ] . V_17 -> V_10 = V_27 ;
V_27 -> V_20 [ V_35 ] . V_17 -> V_21 = V_35 ;
}
}
F_44 ( L_27 , V_36 , V_27 -> V_34 , F_45 ( V_48 ) ) ;
F_91 ( V_126 , V_19 , V_36 ) ;
if ( V_76 ) {
if ( V_36 == 0 && V_126 == V_17 && V_17 -> V_21 == 0 )
F_89 ( V_2 , V_17 ) ;
V_36 = V_17 -> V_21 + 1 ;
V_19 -> V_48 = V_27 -> V_20 [ 0 ] . V_48 ;
V_19 -> V_17 = V_27 ;
V_19 -> V_3 = 0 ;
V_19 -> V_4 = 0 ;
V_19 -> V_22 = 0 ;
V_17 = V_76 ;
goto V_98;
}
F_44 ( L_28 , V_17 -> V_34 + 1 ) ;
V_126 = F_93 ( V_2 -> V_28 , V_11 ) ;
if ( ! V_126 )
return - V_12 ;
V_126 -> V_37 = 2 ;
V_126 -> V_34 = V_17 -> V_34 + 1 ;
F_15 ( V_30 , & V_126 -> V_31 ) ;
F_19 ( & V_2 -> V_38 ) ;
V_126 -> V_20 [ 0 ] . V_48 = V_17 -> V_20 [ 0 ] . V_48 ;
V_126 -> V_20 [ 0 ] . V_17 = V_17 ;
V_126 -> V_20 [ 0 ] . V_3 = V_2 -> V_23 . V_3 ;
V_126 -> V_20 [ 0 ] . V_4 = V_2 -> V_23 . V_4 ;
V_126 -> V_20 [ 0 ] . V_22 = V_2 -> V_23 . V_22 ;
V_126 -> V_20 [ 1 ] . V_48 = V_27 -> V_20 [ 0 ] . V_48 ;
V_126 -> V_20 [ 1 ] . V_17 = V_27 ;
V_2 -> V_23 . V_3 = 0 ;
V_2 -> V_23 . V_4 = 0 ;
V_2 -> V_23 . V_22 = 0 ;
V_2 -> V_23 . V_17 = V_126 ;
V_27 -> V_10 = V_126 ;
V_27 -> V_21 = 1 ;
V_17 -> V_10 = V_126 ;
V_17 -> V_21 = 0 ;
return 0 ;
}
int F_94 ( struct V_1 * V_2 , const union V_63 * V_48 , int V_3 ,
int V_4 , int V_22 )
{
int V_95 , V_36 , V_24 = 0 ;
struct V_16 * V_17 ;
F_72 ( & V_2 -> V_99 ) ;
F_44 ( L_29 , V_3 , V_4 , V_22 , F_45 ( V_48 ) ) ;
V_95 = F_68 ( V_2 , V_48 , & V_17 , & V_36 ) ;
if ( ! V_95 ) {
struct V_18 V_19 ;
V_19 . V_17 = NULL ;
V_19 . V_3 = V_3 ;
V_19 . V_4 = V_4 ;
V_19 . V_22 = V_22 ;
F_90 ( V_2 , V_48 , & V_19 . V_48 ) ;
V_24 = F_92 ( V_2 , V_17 , & V_19 , V_36 + 1 ) ;
} else if ( V_95 == 1 ) {
struct V_18 * V_19 = & V_17 -> V_20 [ V_36 ] ;
F_34 ( V_19 ) ;
V_24 = F_22 ( V_2 , V_19 -> V_3 , V_19 -> V_22 ) ;
V_19 -> V_3 = V_3 ;
V_19 -> V_4 = V_4 ;
V_19 -> V_22 = V_22 ;
} else
V_24 = V_95 ;
if ( ! V_24 )
V_24 = F_95 ( V_2 , 0 ) ;
F_73 ( & V_2 -> V_99 ) ;
return V_24 ;
}
int F_96 ( struct V_1 * V_2 , const union V_63 * V_48 ,
int V_133 , int V_134 , int V_3 , int V_4 , int V_22 )
{
int V_95 , V_36 , V_24 = 0 ;
struct V_16 * V_17 ;
F_72 ( & V_2 -> V_99 ) ;
F_44 ( L_30 , V_133 ,
V_134 , V_3 , V_4 , V_22 , F_45 ( V_48 ) ) ;
V_95 = F_68 ( V_2 , V_48 , & V_17 , & V_36 ) ;
if ( V_95 < 0 ) {
V_24 = V_95 ;
goto V_124;
}
if ( V_95 == 1 ) {
struct V_18 * V_19 = & V_17 -> V_20 [ V_36 ] ;
V_95 = 0 ;
if ( V_19 -> V_3 == V_133 && V_19 -> V_4 == V_134 ) {
F_34 ( V_19 ) ;
V_24 = F_22 ( V_2 , V_19 -> V_3 , V_19 -> V_22 ) ;
if ( V_24 )
goto V_124;
V_19 -> V_3 = V_3 ;
V_19 -> V_4 = V_4 ;
V_19 -> V_22 = V_22 ;
V_95 = 1 ;
} else if ( F_29 ( V_2 , V_48 ) ) {
V_95 = F_62 ( V_2 , V_48 , & V_17 , & V_36 ,
V_133 , V_134 ) ;
F_44 ( L_31 ,
V_95 , V_17 , V_36 , V_133 , V_134 ) ;
if ( V_95 < 0 ) {
V_24 = V_95 ;
goto V_124;
}
if ( V_95 ) {
if ( V_17 -> V_29 || ! F_64 ( V_17 ) ) {
V_17 = F_63 ( V_2 , V_17 ) ;
if ( F_27 ( V_17 ) ) {
V_24 = F_56 ( V_17 ) ;
goto V_124;
}
}
V_19 = & V_17 -> V_20 [ V_36 ] ;
F_34 ( V_19 ) ;
V_24 = F_22 ( V_2 , V_19 -> V_3 ,
V_19 -> V_22 ) ;
if ( V_24 )
goto V_124;
V_19 -> V_3 = V_3 ;
V_19 -> V_4 = V_4 ;
V_19 -> V_22 = V_22 ;
}
}
}
if ( ! V_95 )
V_24 = F_22 ( V_2 , V_3 , V_22 ) ;
if ( ! V_24 )
V_24 = F_95 ( V_2 , 0 ) ;
V_124:
F_73 ( & V_2 -> V_99 ) ;
return V_24 ;
}
int F_97 ( struct V_1 * V_2 , const union V_63 * V_48 ,
int V_3 , int V_4 , int V_22 , const struct V_67 * V_68 )
{
int V_95 , V_36 , V_24 = 0 ;
struct V_16 * V_17 ;
F_72 ( & V_2 -> V_99 ) ;
F_44 ( L_32 , V_3 , V_4 , V_68 -> V_22 , V_68 -> V_71 ,
F_45 ( V_48 ) ) ;
V_95 = F_68 ( V_2 , V_48 , & V_17 , & V_36 ) ;
if ( V_95 < 0 ) {
V_24 = V_95 ;
goto V_124;
}
if ( V_95 == 1 ) {
if ( V_2 -> V_66 )
V_95 = F_60 ( V_2 , V_48 , & V_17 , & V_36 ,
V_68 , 1 ) ;
else
V_95 = F_58 ( V_2 , V_48 , & V_17 , & V_36 , V_68 ) ;
F_44 ( L_23 , V_95 , V_17 , V_36 ) ;
if ( V_95 < 0 ) {
V_24 = V_95 ;
goto V_124;
}
if ( V_17 -> V_29 || ! F_64 ( V_17 ) ) {
V_17 = F_63 ( V_2 , V_17 ) ;
if ( F_27 ( V_17 ) ) {
V_24 = F_56 ( V_17 ) ;
goto V_124;
}
}
if ( V_95 == 1 ) {
struct V_18 * V_19 = & V_17 -> V_20 [ V_36 ] ;
F_34 ( V_19 ) ;
V_24 = F_22 ( V_2 , V_19 -> V_3 , V_19 -> V_22 ) ;
V_19 -> V_3 = V_3 ;
V_19 -> V_4 = V_4 ;
V_19 -> V_22 = V_22 ;
goto V_124;
}
}
if ( ! V_95 ) {
struct V_18 V_19 ;
V_19 . V_17 = NULL ;
V_19 . V_3 = V_3 ;
V_19 . V_4 = V_4 ;
V_19 . V_22 = V_22 ;
F_90 ( V_2 , V_48 , & V_19 . V_48 ) ;
V_24 = F_92 ( V_2 , V_17 , & V_19 , V_36 + 1 ) ;
if ( V_24 )
goto V_124;
if ( V_2 -> V_66 ) {
struct V_67 V_135 = { . V_22 = 0 , . V_71 = L_33 } ;
V_24 = F_95 ( V_2 , 0 ) ;
F_73 ( & V_2 -> V_99 ) ;
if ( V_24 )
return V_24 ;
return F_98 ( V_2 , V_48 , & V_135 ) ;
}
}
V_124:
if ( ! V_24 )
V_24 = F_95 ( V_2 , 0 ) ;
F_73 ( & V_2 -> V_99 ) ;
return V_24 ;
}
static int F_99 ( struct V_1 * V_2 , struct V_16 * V_17 , int V_36 )
{
struct V_18 * V_19 ;
struct V_16 * V_76 ;
int V_35 , V_24 ;
F_17 ( V_17 -> V_34 == 0 ) ;
F_17 ( V_36 >= 0 && V_36 < V_2 -> V_130 ) ;
F_44 ( L_34 , F_45 ( & V_17 -> V_20 [ V_36 ] . V_48 ) ) ;
V_19 = & V_17 -> V_20 [ V_36 ] ;
F_34 ( V_19 ) ;
V_24 = F_22 ( V_2 , V_19 -> V_3 , V_19 -> V_22 ) ;
if ( V_24 ) {
F_100 ( V_2 , V_17 ) ;
return V_24 ;
}
for ( V_35 = V_36 ; V_35 < V_17 -> V_37 - 1 ; V_35 ++ )
V_17 -> V_20 [ V_35 ] = V_17 -> V_20 [ V_35 + 1 ] ;
V_17 -> V_37 -= 1 ;
if ( V_17 -> V_37 > 0 )
return 0 ;
do {
F_17 ( ! F_18 ( V_17 ) ) ;
F_17 ( F_64 ( V_17 ) ) ;
V_76 = V_17 -> V_10 ;
V_36 = V_17 -> V_21 ;
F_26 ( & V_2 -> V_38 ) ;
V_24 = F_9 ( V_2 , V_17 ) ;
if ( V_24 )
return V_24 ;
if ( V_17 -> V_29 ) {
F_15 ( V_33 , & V_17 -> V_31 ) ;
F_19 ( & V_2 -> V_41 ) ;
F_19 ( & V_42 ) ;
} else
F_6 ( V_17 ) ;
V_17 = V_76 ;
} while ( V_17 -> V_37 == 1 );
V_17 -> V_37 -= 1 ;
F_17 ( V_17 -> V_34 != 0 ) ;
for ( V_35 = V_36 ; V_35 < V_17 -> V_37 ; V_35 ++ ) {
V_17 -> V_20 [ V_35 ] = V_17 -> V_20 [ V_35 + 1 ] ;
if ( V_17 -> V_20 [ V_35 ] . V_17 )
V_17 -> V_20 [ V_35 ] . V_17 -> V_21 = V_35 ;
}
if ( ! V_17 -> V_10 ) {
while ( V_17 -> V_37 == 1 && V_17 -> V_34 != 0 ) {
V_76 = V_17 ;
V_19 = & V_17 -> V_20 [ 0 ] ;
V_17 = F_53 ( V_2 , V_17 , 0 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
V_17 = F_23 ( V_2 , V_19 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
V_17 -> V_10 = NULL ;
V_17 -> V_21 = 0 ;
if ( V_2 -> V_23 . V_22 ) {
V_24 = F_1 ( V_2 , V_2 -> V_23 . V_3 ,
V_2 -> V_23 . V_4 ) ;
if ( V_24 )
return V_24 ;
}
V_2 -> V_23 . V_3 = V_19 -> V_3 ;
V_2 -> V_23 . V_4 = V_19 -> V_4 ;
V_2 -> V_23 . V_22 = V_19 -> V_22 ;
V_2 -> V_23 . V_17 = V_17 ;
F_17 ( ! F_18 ( V_76 ) ) ;
F_17 ( F_64 ( V_76 ) ) ;
F_26 ( & V_2 -> V_38 ) ;
if ( V_76 -> V_29 ) {
F_15 ( V_33 , & V_76 -> V_31 ) ;
F_19 ( & V_2 -> V_41 ) ;
F_19 ( & V_42 ) ;
} else
F_6 ( V_76 ) ;
}
}
return 0 ;
}
int F_101 ( struct V_1 * V_2 , const union V_63 * V_48 )
{
int V_95 , V_36 , V_24 = 0 ;
struct V_16 * V_17 ;
F_72 ( & V_2 -> V_99 ) ;
F_44 ( L_21 , F_45 ( V_48 ) ) ;
V_95 = F_68 ( V_2 , V_48 , & V_17 , & V_36 ) ;
if ( V_95 < 0 ) {
V_24 = V_95 ;
goto V_124;
}
if ( V_95 == 1 )
V_24 = F_99 ( V_2 , V_17 , V_36 ) ;
if ( ! V_24 )
V_24 = F_95 ( V_2 , 0 ) ;
V_124:
F_73 ( & V_2 -> V_99 ) ;
return V_24 ;
}
int F_98 ( struct V_1 * V_2 , const union V_63 * V_48 ,
const struct V_67 * V_68 )
{
int V_36 , V_24 ;
struct V_16 * V_17 ;
F_72 ( & V_2 -> V_99 ) ;
F_44 ( L_35 , V_68 -> V_22 , V_68 -> V_71 , F_45 ( V_48 ) ) ;
V_24 = F_68 ( V_2 , V_48 , & V_17 , & V_36 ) ;
if ( V_24 < 0 )
goto V_124;
if ( V_24 ) {
if ( V_2 -> V_66 )
V_24 = F_60 ( V_2 , V_48 , & V_17 , & V_36 ,
V_68 , 0 ) ;
else
V_24 = F_58 ( V_2 , V_48 , & V_17 , & V_36 , V_68 ) ;
F_44 ( L_23 , V_24 , V_17 , V_36 ) ;
if ( V_24 < 0 )
goto V_124;
if ( V_24 ) {
if ( V_17 -> V_29 || ! F_64 ( V_17 ) ) {
V_17 = F_63 ( V_2 , V_17 ) ;
if ( F_27 ( V_17 ) ) {
V_24 = F_56 ( V_17 ) ;
goto V_124;
}
}
V_24 = F_99 ( V_2 , V_17 , V_36 ) ;
}
}
V_124:
if ( ! V_24 )
V_24 = F_95 ( V_2 , 0 ) ;
F_73 ( & V_2 -> V_99 ) ;
return V_24 ;
}
static int F_102 ( struct V_1 * V_2 , union V_63 * V_48 ,
union V_63 * V_136 , union V_63 * V_137 )
{
if ( F_48 ( V_2 , V_48 , V_136 ) < 0 )
return 0 ;
if ( F_48 ( V_2 , V_48 , V_137 ) > 0 )
return 0 ;
return 1 ;
}
int F_103 ( struct V_1 * V_2 , union V_63 * V_136 ,
union V_63 * V_137 )
{
int V_35 , V_36 , V_138 , V_24 = 0 ;
struct V_16 * V_17 ;
union V_63 * V_48 ;
F_72 ( & V_2 -> V_99 ) ;
while ( 1 ) {
V_24 = F_65 ( V_2 , V_136 , & V_17 , & V_36 ) ;
if ( V_24 < 0 )
goto V_124;
if ( V_24 )
V_48 = V_136 ;
else {
V_24 = F_55 ( V_2 , & V_17 , & V_36 ) ;
if ( V_24 == - V_77 ) {
V_24 = 0 ;
goto V_124;
}
if ( V_24 < 0 )
goto V_124;
V_48 = & V_17 -> V_20 [ V_36 ] . V_48 ;
if ( ! F_102 ( V_2 , V_48 , V_136 , V_137 ) ) {
V_24 = 0 ;
goto V_124;
}
}
if ( V_17 -> V_29 || ! F_64 ( V_17 ) ) {
V_17 = F_63 ( V_2 , V_17 ) ;
if ( F_27 ( V_17 ) ) {
V_24 = F_56 ( V_17 ) ;
goto V_124;
}
}
for ( V_35 = V_36 + 1 , V_138 = 0 ; V_35 < V_17 -> V_37 ; V_35 ++ , V_138 ++ ) {
V_48 = & V_17 -> V_20 [ V_35 ] . V_48 ;
if ( ! F_102 ( V_2 , V_48 , V_136 , V_137 ) )
break;
F_34 ( & V_17 -> V_20 [ V_35 ] ) ;
V_24 = F_22 ( V_2 , V_17 -> V_20 [ V_35 ] . V_3 ,
V_17 -> V_20 [ V_35 ] . V_22 ) ;
if ( V_24 ) {
F_100 ( V_2 , V_17 ) ;
goto V_124;
}
F_44 ( L_36 , F_45 ( V_48 ) ) ;
}
if ( V_138 ) {
for ( V_35 = V_36 + 1 + V_138 ; V_35 < V_17 -> V_37 ; V_35 ++ )
V_17 -> V_20 [ V_35 - V_138 ] = V_17 -> V_20 [ V_35 ] ;
V_17 -> V_37 -= V_138 ;
}
V_24 = F_99 ( V_2 , V_17 , V_36 ) ;
if ( V_24 )
goto V_124;
}
V_124:
if ( ! V_24 )
V_24 = F_95 ( V_2 , 0 ) ;
F_73 ( & V_2 -> V_99 ) ;
return V_24 ;
}
int F_104 ( struct V_1 * V_2 , T_2 V_139 )
{
union V_63 V_119 , V_140 ;
struct V_45 * V_141 , * V_142 = NULL ;
struct V_67 V_68 = { . V_71 = NULL } ;
F_44 ( L_37 , ( unsigned long ) V_139 ) ;
F_105 ( V_2 , & V_119 , V_139 ) ;
while ( 1 ) {
T_2 V_143 ;
int V_24 ;
V_141 = F_106 ( V_2 , & V_119 , & V_68 ) ;
if ( F_27 ( V_141 ) ) {
V_24 = F_56 ( V_141 ) ;
if ( V_24 == - V_77 )
break;
return V_24 ;
}
V_143 = F_107 ( V_141 -> V_139 ) ;
F_44 ( L_38 , V_141 -> V_71 ,
( unsigned long ) V_143 ) ;
V_68 . V_71 = V_141 -> V_71 ;
V_68 . V_22 = F_51 ( V_141 -> V_69 ) ;
V_24 = F_98 ( V_2 , & V_119 , & V_68 ) ;
if ( V_24 ) {
F_6 ( V_141 ) ;
return V_24 ;
}
F_108 ( V_2 , & V_119 , V_143 ) ;
F_109 ( V_2 , & V_140 , V_143 ) ;
V_24 = F_103 ( V_2 , & V_119 , & V_140 ) ;
if ( V_24 ) {
F_6 ( V_141 ) ;
return V_24 ;
}
F_6 ( V_142 ) ;
V_142 = V_141 ;
F_47 ( V_2 , & V_141 -> V_48 , & V_119 ) ;
}
F_6 ( V_142 ) ;
F_108 ( V_2 , & V_119 , V_139 ) ;
F_109 ( V_2 , & V_140 , V_139 ) ;
return F_103 ( V_2 , & V_119 , & V_140 ) ;
}
struct V_45 * F_106 ( struct V_1 * V_2 ,
union V_63 * V_48 ,
const struct V_67 * V_68 )
{
int V_36 , V_24 , type = F_46 ( V_2 , V_48 ) ;
struct V_16 * V_17 ;
struct V_45 * V_46 ;
struct V_18 * V_19 ;
union V_63 * V_144 ;
F_44 ( L_39 , V_68 -> V_71 ? ( char * ) V_68 -> V_71 : L_40 , F_45 ( V_48 ) ) ;
F_17 ( F_29 ( V_2 , V_48 ) ) ;
F_72 ( & V_2 -> V_99 ) ;
V_24 = F_65 ( V_2 , V_48 , & V_17 , & V_36 ) ;
if ( F_3 ( V_24 < 0 ) )
goto V_124;
if ( V_68 -> V_71 ) {
if ( V_24 ) {
V_24 = F_58 ( V_2 , V_48 , & V_17 , & V_36 , V_68 ) ;
F_44 ( L_23 ,
V_24 , V_17 , V_36 ) ;
if ( F_3 ( V_24 < 0 ) )
goto V_124;
}
V_24 = F_55 ( V_2 , & V_17 , & V_36 ) ;
if ( F_3 ( V_24 ) )
goto V_124;
} else {
if ( ! V_24 ) {
V_24 = F_55 ( V_2 , & V_17 , & V_36 ) ;
if ( V_24 )
goto V_124;
}
}
V_19 = & V_17 -> V_20 [ V_36 ] ;
V_46 = F_2 ( V_19 -> V_22 , V_11 ) ;
if ( F_3 ( ! V_46 ) ) {
V_24 = - V_12 ;
goto V_124;
}
V_144 = & V_19 -> V_48 ;
if ( F_77 ( V_2 , V_144 ) != F_77 ( V_2 , V_48 ) ||
F_46 ( V_2 , V_144 ) != type ) {
V_24 = - V_77 ;
goto V_70;
}
V_24 = F_35 ( V_2 , V_19 , V_46 ) ;
if ( F_3 ( V_24 ) )
goto V_70;
F_73 ( & V_2 -> V_99 ) ;
return V_46 ;
V_70:
F_6 ( V_46 ) ;
V_124:
F_73 ( & V_2 -> V_99 ) ;
return F_14 ( V_24 ) ;
}
static void F_110 ( struct V_1 * V_2 )
{
struct V_16 * V_29 ;
if ( ! V_2 -> V_29 )
return;
F_17 ( V_2 -> V_145 == V_146 ) ;
V_29 = V_2 -> V_29 ;
do {
struct V_16 * V_17 = V_29 ;
V_29 = V_29 -> V_29 ;
if ( F_18 ( V_17 ) )
F_6 ( V_17 ) ;
} while ( V_29 && V_29 != V_2 -> V_29 );
}
void F_111 ( struct V_1 * V_2 )
{
F_110 ( V_2 ) ;
if ( V_2 -> V_23 . V_17 ) {
long V_36 ;
F_112 ( V_2 -> V_23 . V_17 ) ;
V_36 = F_113 ( & V_2 -> V_41 ) ;
F_114 ( V_36 , & V_42 ) ;
}
F_6 ( V_2 -> V_147 ) ;
F_6 ( V_2 -> V_148 ) ;
F_11 ( V_2 ) ;
}
static struct V_16 * F_115 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
int V_34 = V_17 -> V_34 ;
while ( 1 ) {
int V_36 = V_17 -> V_21 - 1 ;
V_17 = V_17 -> V_10 ;
if ( ! V_17 )
return NULL ;
if ( V_36 >= 0 ) {
V_17 = F_53 ( V_2 , V_17 , V_36 ) ;
if ( F_27 ( V_17 ) )
return V_17 ;
while ( V_17 -> V_34 != V_34 ) {
V_36 = V_17 -> V_37 - 1 ;
V_17 = F_53 ( V_2 , V_17 , V_36 ) ;
if ( F_27 ( V_17 ) )
return V_17 ;
}
break;
}
}
return V_17 ;
}
static struct V_16 * F_116 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
int V_34 = V_17 -> V_34 ;
while ( 1 ) {
int V_36 = V_17 -> V_21 + 1 ;
V_17 = V_17 -> V_10 ;
if ( ! V_17 )
return NULL ;
if ( V_36 < V_17 -> V_37 ) {
V_17 = F_53 ( V_2 , V_17 , V_36 ) ;
if ( F_27 ( V_17 ) )
return V_17 ;
while ( V_17 -> V_34 != V_34 ) {
V_17 = F_53 ( V_2 , V_17 , 0 ) ;
if ( F_27 ( V_17 ) )
return V_17 ;
}
break;
}
}
return V_17 ;
}
static struct V_16 * F_117 ( struct V_1 * V_2 ,
union V_63 * V_48 , int V_34 ,
int V_3 , int V_4 )
{
struct V_16 * V_17 , * V_27 ;
int V_36 , V_75 ;
F_17 ( F_46 ( V_2 , V_48 ) < V_90 ) ;
if ( V_34 < 0 )
return F_14 ( - V_78 ) ;
V_17 = V_2 -> V_23 . V_17 ;
if ( ! V_17 ) {
V_17 = F_54 ( V_2 , & V_2 -> V_23 , NULL , 0 ) ;
if ( F_27 ( V_17 ) )
return V_17 ;
}
if ( V_2 -> V_23 . V_3 == V_3 && V_2 -> V_23 . V_4 == V_4 )
return V_17 ;
if ( V_34 >= V_17 -> V_34 )
return NULL ;
while ( 1 ) {
F_67 ( V_2 , V_17 , V_48 , & V_36 ) ;
if ( V_36 < 0 ) {
V_17 = F_115 ( V_2 , V_17 ) ;
if ( ! V_17 )
return NULL ;
if ( F_27 ( V_17 ) )
return V_17 ;
F_67 ( V_2 , V_17 , V_48 , & V_36 ) ;
F_17 ( V_36 >= 0 ) ;
}
if ( V_17 -> V_34 == V_34 + 1 )
break;
V_17 = F_53 ( V_2 , V_17 , V_36 ) ;
if ( F_27 ( V_17 ) )
return V_17 ;
}
if ( V_17 -> V_20 [ V_36 ] . V_3 == V_3 && V_17 -> V_20 [ V_36 ] . V_4 == V_4 )
return F_53 ( V_2 , V_17 , V_36 ) ;
if ( ! F_29 ( V_2 , V_48 ) )
return NULL ;
V_27 = V_17 ;
V_75 = V_36 ;
while ( 1 ) {
if ( V_36 )
V_36 -= 1 ;
else {
V_17 = F_115 ( V_2 , V_17 ) ;
if ( ! V_17 )
break;
if ( F_27 ( V_17 ) )
return V_17 ;
V_36 = V_17 -> V_37 - 1 ;
}
if ( V_17 -> V_20 [ V_36 ] . V_3 == V_3 &&
V_17 -> V_20 [ V_36 ] . V_4 == V_4 )
return F_53 ( V_2 , V_17 , V_36 ) ;
if ( F_48 ( V_2 , & V_17 -> V_20 [ V_36 ] . V_48 , V_48 ) < 0 )
break;
}
V_17 = V_27 ;
V_36 = V_75 ;
while ( 1 ) {
if ( ++ V_36 >= V_17 -> V_37 ) {
V_17 = F_116 ( V_2 , V_17 ) ;
if ( ! V_17 )
break;
if ( F_27 ( V_17 ) )
return V_17 ;
V_36 = 0 ;
}
if ( V_17 -> V_20 [ V_36 ] . V_3 == V_3 &&
V_17 -> V_20 [ V_36 ] . V_4 == V_4 )
return F_53 ( V_2 , V_17 , V_36 ) ;
if ( F_48 ( V_2 , & V_17 -> V_20 [ V_36 ] . V_48 , V_48 ) > 0 )
break;
}
return NULL ;
}
int F_118 ( struct V_1 * V_2 , union V_63 * V_48 , int V_34 ,
int V_3 , int V_4 )
{
struct V_16 * V_17 ;
V_17 = F_117 ( V_2 , V_48 , V_34 , V_3 , V_4 ) ;
if ( ! V_17 )
return 0 ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
return F_64 ( V_17 ) ? 1 : 2 ;
}
static int F_119 ( struct V_1 * V_2 , union V_63 * V_48 ,
int V_3 , int V_4 )
{
struct V_18 * V_19 ;
struct V_16 * V_17 , * V_27 ;
int V_36 , V_95 , V_24 , V_75 ;
const int V_149 = ! F_29 ( V_2 , V_48 ) ;
V_95 = F_65 ( V_2 , V_48 , & V_17 , & V_36 ) ;
if ( V_95 < 0 )
return V_95 ;
if ( ! V_95 )
return 0 ;
V_19 = & V_17 -> V_20 [ V_36 ] ;
if ( V_3 == V_19 -> V_3 && V_4 == V_19 -> V_4 )
return 1 ;
if ( V_149 )
return 0 ;
V_27 = V_17 ;
V_75 = V_36 ;
while ( 1 ) {
V_24 = F_57 ( V_2 , & V_17 , & V_36 ) ;
if ( V_24 == - V_77 )
break;
if ( V_24 )
return V_24 ;
if ( F_48 ( V_2 , V_48 , & V_17 -> V_20 [ V_36 ] . V_48 ) )
break;
V_19 = & V_17 -> V_20 [ V_36 ] ;
if ( V_3 == V_19 -> V_3 && V_4 == V_19 -> V_4 )
return 1 ;
}
V_17 = V_27 ;
V_36 = V_75 ;
while ( 1 ) {
V_24 = F_55 ( V_2 , & V_17 , & V_36 ) ;
if ( V_24 ) {
if ( V_24 == - V_77 )
return 0 ;
return V_24 ;
}
if ( F_48 ( V_2 , V_48 , & V_17 -> V_20 [ V_36 ] . V_48 ) )
break;
V_19 = & V_17 -> V_20 [ V_36 ] ;
if ( V_3 == V_19 -> V_3 && V_4 == V_19 -> V_4 )
return 1 ;
}
return 0 ;
}
int F_120 ( struct V_1 * V_2 , union V_63 * V_48 , int V_34 ,
int V_3 , int V_4 , int V_150 )
{
int V_24 ;
F_72 ( & V_2 -> V_99 ) ;
if ( V_150 ) {
V_24 = F_118 ( V_2 , V_48 , V_34 , V_3 , V_4 ) ;
if ( V_24 < 0 )
goto V_124;
if ( V_24 == 1 )
V_24 = 0 ;
else if ( V_24 == 2 )
V_24 = 1 ;
else
F_121 ( V_24 != 0 ) ;
} else
V_24 = F_119 ( V_2 , V_48 , V_3 , V_4 ) ;
V_124:
F_73 ( & V_2 -> V_99 ) ;
return V_24 ;
}
int F_122 ( struct V_1 * V_2 , union V_63 * V_48 , int V_34 ,
int V_3 , int V_4 )
{
struct V_16 * V_17 ;
int V_24 = 0 ;
F_72 ( & V_2 -> V_99 ) ;
V_17 = F_117 ( V_2 , V_48 , V_34 , V_3 , V_4 ) ;
if ( ! V_17 )
goto V_124;
if ( F_27 ( V_17 ) ) {
V_24 = F_56 ( V_17 ) ;
goto V_124;
}
V_17 = F_63 ( V_2 , V_17 ) ;
if ( F_27 ( V_17 ) ) {
V_24 = F_56 ( V_17 ) ;
goto V_124;
}
V_124:
F_73 ( & V_2 -> V_99 ) ;
return V_24 ;
}
int F_123 ( struct V_1 * V_2 , const struct V_151 * V_151 ,
T_3 V_152 )
{
int V_24 , V_36 ;
union V_63 V_136 , V_137 , * V_48 ;
struct V_16 * V_17 ;
unsigned int V_103 ;
if ( ! F_124 ( V_151 -> V_153 ) )
return 0 ;
if ( ! F_125 ( V_2 ) )
return 0 ;
V_103 = ( V_152 + V_154 - 1 ) >> V_155 ;
F_126 ( V_2 , & V_136 , V_151 -> V_156 , V_103 ) ;
F_127 ( V_2 , & V_137 , V_151 -> V_156 ) ;
F_72 ( & V_2 -> V_99 ) ;
V_24 = F_65 ( V_2 , & V_136 , & V_17 , & V_36 ) ;
if ( V_24 < 0 )
goto V_124;
if ( V_24 ) {
V_24 = - V_78 ;
V_48 = & V_136 ;
goto V_157;
}
V_24 = F_55 ( V_2 , & V_17 , & V_36 ) ;
if ( V_24 == - V_77 ) {
V_24 = 0 ;
goto V_124;
}
if ( V_24 < 0 )
goto V_124;
F_17 ( V_24 == 0 ) ;
V_48 = & V_17 -> V_20 [ V_36 ] . V_48 ;
if ( ! F_102 ( V_2 , V_48 , & V_136 , & V_137 ) )
goto V_124;
V_157:
V_103 = F_76 ( V_2 , V_48 ) ;
F_5 ( L_41
L_42 , ( unsigned long ) V_151 -> V_156 , V_152 ,
( ( T_3 ) V_103 ) << V_155 , F_45 ( V_48 ) ) ;
F_73 ( & V_2 -> V_99 ) ;
F_128 ( V_2 , V_151 ) ;
F_31 () ;
return - V_78 ;
V_124:
F_73 ( & V_2 -> V_99 ) ;
return V_24 ;
}
