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
F_17 ( ! F_18 ( V_33 , & V_17 -> V_31 ) ) ;
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
if ( ! F_18 ( V_32 , & V_17 -> V_31 ) ) {
if ( ! F_24 ( V_30 , & V_17 -> V_31 ) ) {
F_19 ( & V_2 -> V_38 ) ;
F_25 ( & V_2 -> V_41 ) ;
F_25 ( & V_42 ) ;
V_24 = F_20 ( V_2 , V_19 -> V_3 , V_19 -> V_22 ) ;
if ( F_3 ( V_24 ) )
return F_14 ( V_24 ) ;
}
return V_17 ;
}
V_27 = F_13 ( V_2 , V_17 ) ;
if ( F_26 ( V_27 ) )
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
static int F_27 ( struct V_1 * V_2 , struct V_18 * V_19 ,
const void * V_43 )
{
int V_24 ;
void * V_44 ;
const struct V_45 * V_46 = V_43 ;
F_17 ( ! V_19 -> V_47 ) ;
F_17 ( V_19 -> V_22 != 0 ) ;
F_17 ( F_28 ( V_2 , & V_19 -> V_48 ) ) ;
V_24 = F_29 ( V_2 , V_46 ) ;
if ( V_24 ) {
F_30 () ;
F_31 ( V_2 , V_46 ) ;
return V_24 ;
}
V_44 = F_2 ( V_19 -> V_22 , V_11 ) ;
if ( ! V_44 )
return 0 ;
memcpy ( V_44 , V_43 , V_19 -> V_22 ) ;
V_19 -> V_47 = V_44 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_18 * V_19 ,
void * V_43 )
{
int V_24 ;
F_17 ( ! V_19 -> V_47 ) ;
F_17 ( V_19 -> V_22 != 0 ) ;
V_24 = F_29 ( V_2 , V_43 ) ;
if ( V_24 ) {
F_30 () ;
F_31 ( V_2 , V_43 ) ;
return V_24 ;
}
V_19 -> V_47 = V_43 ;
return 0 ;
}
static void F_33 ( struct V_18 * V_19 )
{
if ( ! V_19 -> V_47 )
return;
F_6 ( V_19 -> V_47 ) ;
V_19 -> V_47 = NULL ;
}
static int F_34 ( struct V_1 * V_2 , struct V_18 * V_19 ,
void * V_43 )
{
int V_24 ;
F_17 ( F_28 ( V_2 , & V_19 -> V_48 ) ) ;
if ( V_19 -> V_47 ) {
F_17 ( V_19 -> V_22 != 0 ) ;
memcpy ( V_43 , V_19 -> V_47 , V_19 -> V_22 ) ;
return 0 ;
}
V_24 = F_35 ( V_2 , V_19 , V_43 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_27 ( V_2 , V_19 , V_43 ) ;
return V_24 ;
}
static int F_36 ( const struct V_1 * V_2 , void * V_49 , int type ,
int V_22 , int V_3 , int V_4 )
{
int V_24 , V_50 ;
struct V_51 * V_52 = V_49 ;
T_1 V_53 , V_54 ;
F_37 ( L_2 , V_3 , V_4 , F_38 ( type ) , V_22 ) ;
V_24 = F_39 ( V_2 -> V_55 , V_3 , V_49 , V_4 , V_22 ) ;
if ( V_24 ) {
F_5 ( L_3 ,
type , V_3 , V_4 , V_24 ) ;
return V_24 ;
}
if ( F_40 ( V_52 -> V_56 ) != V_57 )
return 0 ;
if ( V_52 -> V_58 != type )
return 0 ;
V_50 = F_40 ( V_52 -> V_22 ) ;
if ( V_50 != V_22 )
return 0 ;
if ( type == V_59 && V_2 -> V_60 && ! V_2 -> V_61 &&
! V_2 -> V_62 )
return 1 ;
V_53 = F_41 ( V_63 , V_49 + 8 , V_50 - 8 ) ;
V_54 = F_40 ( V_52 -> V_53 ) ;
if ( V_53 != V_54 )
return 0 ;
return 1 ;
}
static int F_42 ( struct V_1 * V_2 , const union V_64 * V_48 ,
struct V_18 * V_19 , void * V_43 )
{
int V_65 ;
F_43 ( L_4 , V_19 -> V_3 , V_19 -> V_4 , F_44 ( V_48 ) ) ;
V_65 = F_36 ( V_2 , V_43 , F_45 ( V_2 , V_48 ) , V_19 -> V_22 , V_19 -> V_3 ,
V_19 -> V_4 ) ;
if ( V_65 == 1 ) {
union V_64 V_66 ;
struct V_45 * V_46 = V_43 ;
F_46 ( V_2 , & V_46 -> V_48 , & V_66 ) ;
if ( F_47 ( V_2 , V_48 , & V_66 ) != 0 )
V_65 = 0 ;
}
if ( V_65 == 0 && V_2 -> V_67 )
F_48 ( L_5 ,
V_19 -> V_3 , V_19 -> V_4 , V_19 -> V_22 , F_44 ( V_48 ) ) ;
return V_65 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_18 * V_19 ,
const struct V_68 * V_69 )
{
struct V_45 * V_46 ;
int V_70 , V_24 ;
if ( ! V_19 -> V_47 ) {
V_46 = F_2 ( V_19 -> V_22 , V_11 ) ;
if ( ! V_46 )
return - V_12 ;
V_24 = F_35 ( V_2 , V_19 , V_46 ) ;
if ( V_24 )
goto V_71;
V_24 = F_32 ( V_2 , V_19 , V_46 ) ;
if ( V_24 )
goto V_71;
} else
V_46 = V_19 -> V_47 ;
V_70 = F_50 ( V_46 -> V_70 ) ;
V_24 = memcmp ( V_46 -> V_72 , V_69 -> V_72 , F_51 ( int , V_70 , V_69 -> V_22 ) ) ;
if ( V_24 == 0 ) {
if ( V_70 == V_69 -> V_22 )
return V_73 ;
else if ( V_70 < V_69 -> V_22 )
return V_74 ;
else
return V_75 ;
} else if ( V_24 < 0 )
return V_74 ;
else
return V_75 ;
V_71:
F_6 ( V_46 ) ;
return V_24 ;
}
static struct V_16 * F_52 ( struct V_1 * V_2 ,
struct V_16 * V_17 , int V_36 )
{
struct V_18 * V_19 ;
V_19 = & V_17 -> V_20 [ V_36 ] ;
if ( V_19 -> V_17 )
V_17 = V_19 -> V_17 ;
else
V_17 = F_53 ( V_2 , V_19 , V_17 , V_36 ) ;
return V_17 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_16 * * V_27 , int * V_36 )
{
struct V_16 * V_17 = * V_27 ;
int V_76 = * V_36 ;
V_76 += 1 ;
if ( V_76 < V_17 -> V_37 ) {
* V_36 = V_76 ;
return 0 ;
}
while ( 1 ) {
struct V_16 * V_77 ;
V_77 = V_17 -> V_10 ;
if ( ! V_77 )
return - V_78 ;
V_76 = V_17 -> V_21 + 1 ;
V_17 = V_77 ;
if ( V_76 < V_17 -> V_37 ) {
V_17 = F_52 ( V_2 , V_17 , V_76 ) ;
if ( F_26 ( V_17 ) )
return F_55 ( V_17 ) ;
while ( V_17 -> V_34 != 0 ) {
V_17 = F_52 ( V_2 , V_17 , 0 ) ;
if ( F_26 ( V_17 ) )
return F_55 ( V_17 ) ;
}
V_76 = 0 ;
break;
}
}
* V_27 = V_17 ;
* V_36 = V_76 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_16 * * V_27 , int * V_36 )
{
struct V_16 * V_17 = * V_27 ;
int V_76 = * V_36 ;
if ( V_76 > 0 ) {
* V_36 = V_76 - 1 ;
return 0 ;
}
while ( 1 ) {
struct V_16 * V_77 ;
V_77 = V_17 -> V_10 ;
if ( ! V_77 )
return - V_78 ;
V_76 = V_17 -> V_21 - 1 ;
V_17 = V_77 ;
if ( V_76 >= 0 ) {
V_17 = F_52 ( V_2 , V_17 , V_76 ) ;
if ( F_26 ( V_17 ) )
return F_55 ( V_17 ) ;
while ( V_17 -> V_34 != 0 ) {
V_76 = V_17 -> V_37 - 1 ;
V_17 = F_52 ( V_2 , V_17 , V_76 ) ;
if ( F_26 ( V_17 ) )
return F_55 ( V_17 ) ;
}
V_76 = V_17 -> V_37 - 1 ;
break;
}
}
* V_27 = V_17 ;
* V_36 = V_76 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , const union V_64 * V_48 ,
struct V_16 * * V_27 , int * V_36 ,
const struct V_68 * V_69 )
{
int V_24 ;
V_24 = F_49 ( V_2 , & ( * V_27 ) -> V_20 [ * V_36 ] , V_69 ) ;
if ( F_3 ( V_24 < 0 ) )
return V_24 ;
if ( V_24 == V_73 )
return 1 ;
if ( V_24 == V_75 ) {
while ( 1 ) {
V_24 = F_56 ( V_2 , V_27 , V_36 ) ;
if ( V_24 == - V_78 ) {
F_17 ( * V_36 == 0 ) ;
* V_36 = - 1 ;
return 0 ;
}
if ( V_24 < 0 )
return V_24 ;
if ( F_47 ( V_2 , & ( * V_27 ) -> V_20 [ * V_36 ] . V_48 , V_48 ) ) {
if ( * V_36 == ( * V_27 ) -> V_37 - 1 ) {
V_24 = F_54 ( V_2 , V_27 , V_36 ) ;
if ( V_24 ) {
F_17 ( 0 ) ;
if ( V_24 == - V_78 )
V_24 = - V_79 ;
return V_24 ;
}
F_17 ( * V_36 == 0 ) ;
* V_36 = - 1 ;
}
return 0 ;
}
V_24 = F_49 ( V_2 , & ( * V_27 ) -> V_20 [ * V_36 ] , V_69 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_24 == V_74 )
return 0 ;
if ( V_24 == V_73 )
return 1 ;
F_17 ( V_24 == V_75 ) ;
}
} else {
int V_76 = * V_36 ;
struct V_16 * V_17 = * V_27 ;
while ( 1 ) {
V_24 = F_54 ( V_2 , & V_17 , & V_76 ) ;
if ( V_24 == - V_78 )
return 0 ;
if ( V_24 < 0 )
return V_24 ;
if ( F_47 ( V_2 , & V_17 -> V_20 [ V_76 ] . V_48 , V_48 ) )
return 0 ;
V_24 = F_49 ( V_2 , & V_17 -> V_20 [ V_76 ] , V_69 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_24 == V_75 )
return 0 ;
* V_27 = V_17 ;
* V_36 = V_76 ;
if ( V_24 == V_73 )
return 1 ;
F_17 ( V_24 == V_74 ) ;
}
}
}
static int F_58 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
const struct V_68 * V_69 )
{
struct V_45 * V_46 ;
int V_70 , V_24 ;
if ( ! V_19 -> V_47 ) {
V_46 = F_2 ( V_19 -> V_22 , V_11 ) ;
if ( ! V_46 )
return - V_12 ;
V_24 = F_42 ( V_2 , & V_19 -> V_48 , V_19 , V_46 ) ;
if ( V_24 < 0 )
goto V_71;
if ( V_24 == 0 ) {
V_24 = V_80 ;
goto V_71;
}
F_17 ( V_24 == 1 ) ;
V_24 = F_32 ( V_2 , V_19 , V_46 ) ;
if ( V_24 )
goto V_71;
} else
V_46 = V_19 -> V_47 ;
V_70 = F_50 ( V_46 -> V_70 ) ;
V_24 = memcmp ( V_46 -> V_72 , V_69 -> V_72 , F_51 ( int , V_70 , V_69 -> V_22 ) ) ;
if ( V_24 == 0 ) {
if ( V_70 == V_69 -> V_22 )
return V_73 ;
else if ( V_70 < V_69 -> V_22 )
return V_74 ;
else
return V_75 ;
} else if ( V_24 < 0 )
return V_74 ;
else
return V_75 ;
V_71:
F_6 ( V_46 ) ;
return V_24 ;
}
static int F_59 ( struct V_1 * V_2 ,
const union V_64 * V_48 ,
struct V_16 * * V_27 , int * V_36 ,
const struct V_68 * V_69 , int V_81 )
{
struct V_16 * V_82 = NULL , * V_17 = * V_27 ;
int V_83 ( V_84 ) , V_24 , V_85 , V_86 = 0 , V_76 = * V_36 ;
V_85 = F_58 ( V_2 , & V_17 -> V_20 [ V_76 ] , V_69 ) ;
if ( F_3 ( V_85 < 0 ) )
return V_85 ;
if ( V_85 == V_73 )
return 1 ;
if ( V_85 == V_80 ) {
V_82 = V_17 ;
V_84 = V_76 ;
V_86 = 1 ;
} else if ( ! V_81 )
V_86 = 1 ;
if ( V_85 == V_75 || V_86 ) {
while ( 1 ) {
V_24 = F_56 ( V_2 , V_27 , V_36 ) ;
if ( V_24 == - V_78 ) {
F_17 ( * V_36 == 0 ) ;
* V_36 = - 1 ;
break;
}
if ( V_24 < 0 )
return V_24 ;
if ( F_47 ( V_2 , & ( * V_27 ) -> V_20 [ * V_36 ] . V_48 , V_48 ) ) {
if ( * V_36 == ( * V_27 ) -> V_37 - 1 ) {
V_24 = F_54 ( V_2 , V_27 , V_36 ) ;
if ( V_24 ) {
F_17 ( 0 ) ;
if ( V_24 == - V_78 )
V_24 = - V_79 ;
return V_24 ;
}
F_17 ( * V_36 == 0 ) ;
* V_36 = - 1 ;
}
break;
}
V_24 = F_58 ( V_2 , & ( * V_27 ) -> V_20 [ * V_36 ] , V_69 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_24 == V_73 )
return 1 ;
if ( V_24 == V_80 ) {
V_82 = * V_27 ;
V_84 = * V_36 ;
continue;
}
if ( ! V_81 )
continue;
if ( V_24 == V_74 )
break;
else
V_86 = 0 ;
}
}
if ( V_85 == V_74 || V_86 ) {
* V_27 = V_17 ;
* V_36 = V_76 ;
while ( 1 ) {
V_24 = F_54 ( V_2 , & V_17 , & V_76 ) ;
if ( V_24 == - V_78 )
break;
if ( V_24 < 0 )
return V_24 ;
if ( F_47 ( V_2 , & V_17 -> V_20 [ V_76 ] . V_48 , V_48 ) )
break;
V_24 = F_58 ( V_2 , & V_17 -> V_20 [ V_76 ] , V_69 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_24 == V_75 )
break;
* V_27 = V_17 ;
* V_36 = V_76 ;
if ( V_24 == V_73 )
return 1 ;
if ( V_24 == V_80 ) {
V_82 = V_17 ;
V_84 = V_76 ;
}
}
}
if ( V_81 || ! V_82 )
return 0 ;
F_48 ( L_6 ,
V_82 -> V_20 [ V_84 ] . V_3 , V_82 -> V_20 [ V_84 ] . V_4 ,
V_82 -> V_20 [ V_84 ] . V_22 , F_44 ( V_48 ) ) ;
* V_27 = V_82 ;
* V_36 = V_84 ;
return 1 ;
}
static int F_60 ( struct V_18 * V_19 , int V_3 , int V_4 )
{
if ( V_19 -> V_3 == V_3 && V_19 -> V_4 == V_4 )
return 1 ;
else
return 0 ;
}
static int F_61 ( struct V_1 * V_2 ,
const union V_64 * V_48 ,
struct V_16 * * V_27 , int * V_36 ,
int V_3 , int V_4 )
{
struct V_16 * V_17 ;
int V_76 , V_24 ;
V_17 = * V_27 ;
V_76 = * V_36 ;
if ( F_60 ( & V_17 -> V_20 [ V_76 ] , V_3 , V_4 ) )
return 1 ;
while ( 1 ) {
V_24 = F_56 ( V_2 , & V_17 , & V_76 ) ;
if ( V_24 == - V_78 )
break;
if ( V_24 < 0 )
return V_24 ;
if ( F_47 ( V_2 , & V_17 -> V_20 [ V_76 ] . V_48 , V_48 ) )
break;
if ( F_60 ( & V_17 -> V_20 [ V_76 ] , V_3 , V_4 ) ) {
* V_27 = V_17 ;
* V_36 = V_76 ;
return 1 ;
}
}
V_17 = * V_27 ;
V_76 = * V_36 ;
while ( 1 ) {
V_24 = F_54 ( V_2 , & V_17 , & V_76 ) ;
if ( V_24 == - V_78 )
return 0 ;
if ( V_24 < 0 )
return V_24 ;
if ( F_47 ( V_2 , & V_17 -> V_20 [ V_76 ] . V_48 , V_48 ) )
return 0 ;
* V_27 = V_17 ;
* V_36 = V_76 ;
if ( F_60 ( & V_17 -> V_20 [ V_76 ] , V_3 , V_4 ) )
return 1 ;
}
}
static struct V_16 * F_62 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_16 * V_77 ;
int * V_87 = V_2 -> V_88 , V_9 = 0 ;
F_17 ( V_2 -> V_23 . V_17 ) ;
F_17 ( V_17 ) ;
if ( V_2 -> V_23 . V_17 -> V_34 > V_89 ) {
F_6 ( V_2 -> V_88 ) ;
V_2 -> V_88 = F_2 ( V_2 -> V_23 . V_17 -> V_34 * sizeof( int ) ,
V_11 ) ;
if ( ! V_2 -> V_88 )
return F_14 ( - V_12 ) ;
V_87 = V_2 -> V_88 ;
}
if ( V_2 -> V_23 . V_17 -> V_34 ) {
while ( 1 ) {
int V_36 ;
V_77 = V_17 -> V_10 ;
if ( ! V_77 )
break;
V_36 = V_17 -> V_21 ;
F_17 ( V_9 < V_2 -> V_23 . V_17 -> V_34 ) ;
V_87 [ V_9 ++ ] = V_36 ;
if ( ! V_77 -> V_29 && F_63 ( V_17 ) )
break;
V_17 = V_77 ;
}
}
while ( 1 ) {
struct V_18 * V_19 ;
V_77 = V_17 -> V_10 ;
if ( V_77 ) {
F_17 ( V_87 [ V_9 - 1 ] >= 0 ) ;
F_17 ( V_87 [ V_9 - 1 ] < V_77 -> V_37 ) ;
V_19 = & V_77 -> V_20 [ V_87 [ -- V_9 ] ] ;
V_17 = F_23 ( V_2 , V_19 ) ;
} else {
F_17 ( V_17 == V_2 -> V_23 . V_17 ) ;
V_17 = F_23 ( V_2 , & V_2 -> V_23 ) ;
}
if ( F_26 ( V_17 ) || ! V_9 )
break;
F_17 ( V_87 [ V_9 - 1 ] >= 0 ) ;
F_17 ( V_87 [ V_9 - 1 ] < V_17 -> V_37 ) ;
V_17 = V_17 -> V_20 [ V_87 [ V_9 - 1 ] ] . V_17 ;
}
return V_17 ;
}
int F_64 ( struct V_1 * V_2 , const union V_64 * V_48 ,
struct V_16 * * V_27 , int * V_36 )
{
int V_24 , V_90 ;
struct V_16 * V_17 ;
unsigned long time = F_65 () ;
F_43 ( L_7 , F_44 ( V_48 ) ) ;
F_17 ( F_45 ( V_2 , V_48 ) < V_91 ) ;
V_17 = V_2 -> V_23 . V_17 ;
if ( F_3 ( ! V_17 ) ) {
V_17 = F_53 ( V_2 , & V_2 -> V_23 , NULL , 0 ) ;
if ( F_26 ( V_17 ) )
return F_55 ( V_17 ) ;
}
V_17 -> time = time ;
while ( 1 ) {
struct V_18 * V_19 ;
V_90 = F_66 ( V_2 , V_17 , V_48 , V_36 ) ;
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
V_17 = F_53 ( V_2 , V_19 , V_17 , * V_36 ) ;
if ( F_26 ( V_17 ) )
return F_55 ( V_17 ) ;
}
* V_27 = V_17 ;
if ( V_90 || ! F_28 ( V_2 , V_48 ) || * V_36 != - 1 ) {
F_43 ( L_8 , V_90 , V_17 -> V_34 , * V_36 ) ;
return V_90 ;
}
V_24 = F_56 ( V_2 , & V_17 , V_36 ) ;
if ( V_24 == - V_78 ) {
F_43 ( L_9 , V_17 -> V_34 ) ;
* V_36 = - 1 ;
return 0 ;
}
if ( F_3 ( V_24 < 0 ) )
return V_24 ;
if ( F_47 ( V_2 , V_48 , & V_17 -> V_20 [ * V_36 ] . V_48 ) ) {
F_43 ( L_9 , V_17 -> V_34 ) ;
* V_36 = - 1 ;
return 0 ;
}
F_43 ( L_10 , V_17 -> V_34 , * V_36 ) ;
* V_27 = V_17 ;
return 1 ;
}
static int F_67 ( struct V_1 * V_2 , const union V_64 * V_48 ,
struct V_16 * * V_27 , int * V_36 )
{
int V_24 , V_90 ;
struct V_16 * V_17 ;
unsigned long time = F_65 () ;
F_43 ( L_11 , F_44 ( V_48 ) ) ;
V_17 = V_2 -> V_23 . V_17 ;
if ( F_3 ( ! V_17 ) ) {
V_17 = F_53 ( V_2 , & V_2 -> V_23 , NULL , 0 ) ;
if ( F_26 ( V_17 ) )
return F_55 ( V_17 ) ;
}
V_17 = F_23 ( V_2 , & V_2 -> V_23 ) ;
if ( F_26 ( V_17 ) )
return F_55 ( V_17 ) ;
V_17 -> time = time ;
while ( 1 ) {
struct V_18 * V_19 ;
V_90 = F_66 ( V_2 , V_17 , V_48 , V_36 ) ;
if ( V_17 -> V_34 == 0 )
break;
if ( * V_36 < 0 )
* V_36 = 0 ;
V_19 = & V_17 -> V_20 [ * V_36 ] ;
if ( V_19 -> V_17 ) {
V_17 -> time = time ;
V_17 = F_23 ( V_2 , V_19 ) ;
if ( F_26 ( V_17 ) )
return F_55 ( V_17 ) ;
continue;
}
V_17 = F_53 ( V_2 , V_19 , V_17 , * V_36 ) ;
if ( F_26 ( V_17 ) )
return F_55 ( V_17 ) ;
V_17 = F_23 ( V_2 , V_19 ) ;
if ( F_26 ( V_17 ) )
return F_55 ( V_17 ) ;
}
* V_27 = V_17 ;
if ( V_90 || ! F_28 ( V_2 , V_48 ) || * V_36 != - 1 ) {
F_43 ( L_8 , V_90 , V_17 -> V_34 , * V_36 ) ;
return V_90 ;
}
V_24 = F_56 ( V_2 , & V_17 , V_36 ) ;
if ( V_24 == - V_78 ) {
* V_36 = - 1 ;
F_43 ( L_9 , V_17 -> V_34 ) ;
return 0 ;
}
if ( F_3 ( V_24 < 0 ) )
return V_24 ;
if ( F_47 ( V_2 , V_48 , & V_17 -> V_20 [ * V_36 ] . V_48 ) ) {
* V_36 = - 1 ;
F_43 ( L_9 , V_17 -> V_34 ) ;
return 0 ;
}
if ( V_17 -> V_29 || ! F_63 ( V_17 ) ) {
V_17 = F_62 ( V_2 , V_17 ) ;
if ( F_26 ( V_17 ) )
return F_55 ( V_17 ) ;
}
F_43 ( L_10 , V_17 -> V_34 , * V_36 ) ;
* V_27 = V_17 ;
return 1 ;
}
static int F_68 ( struct V_1 * V_2 , int V_3 , int V_92 )
{
int V_93 , V_94 ;
V_94 = V_2 -> V_94 ;
F_69 () ;
V_93 = V_2 -> V_95 ;
if ( V_92 == V_93 )
return 0 ;
if ( V_92 + 1 != V_93 )
return 1 ;
F_69 () ;
if ( V_94 != V_2 -> V_94 )
return 1 ;
if ( V_94 == V_3 )
return 1 ;
return 0 ;
}
int F_70 ( struct V_1 * V_2 , const union V_64 * V_48 ,
void * V_43 , int * V_3 , int * V_4 )
{
int V_96 , V_36 , V_24 , V_97 = 0 , V_92 ;
struct V_16 * V_17 ;
struct V_18 V_19 , * V_98 ;
V_99:
F_71 ( & V_2 -> V_100 ) ;
V_96 = F_64 ( V_2 , V_48 , & V_17 , & V_36 ) ;
if ( ! V_96 ) {
V_24 = - V_78 ;
goto V_101;
} else if ( V_96 < 0 ) {
V_24 = V_96 ;
goto V_101;
}
V_98 = & V_17 -> V_20 [ V_36 ] ;
if ( V_3 ) {
* V_3 = V_98 -> V_3 ;
* V_4 = V_98 -> V_4 ;
}
if ( F_28 ( V_2 , V_48 ) ) {
V_24 = F_34 ( V_2 , V_98 , V_43 ) ;
goto V_101;
}
if ( V_97 ) {
V_24 = F_35 ( V_2 , V_98 , V_43 ) ;
goto V_101;
}
V_19 = V_17 -> V_20 [ V_36 ] ;
V_92 = V_2 -> V_95 ;
F_72 ( & V_2 -> V_100 ) ;
if ( F_73 ( V_2 , V_19 . V_3 ) ) {
V_24 = F_35 ( V_2 , & V_19 , V_43 ) ;
return V_24 ;
}
V_24 = F_42 ( V_2 , V_48 , & V_19 , V_43 ) ;
if ( V_24 <= 0 || F_68 ( V_2 , V_19 . V_3 , V_92 ) ) {
V_97 = 1 ;
goto V_99;
}
return 0 ;
V_101:
F_72 ( & V_2 -> V_100 ) ;
return V_24 ;
}
int F_74 ( struct V_1 * V_2 , struct V_102 * V_103 )
{
int V_36 , V_24 = 0 , V_3 = - 1 , V_83 ( V_4 ) ;
int V_83 ( V_22 ) ;
unsigned int V_104 = F_75 ( V_2 , & V_103 -> V_48 ) ;
struct V_16 * V_17 ;
V_103 -> V_105 = 0 ;
V_103 -> V_106 = 0 ;
V_103 -> V_107 = 0 ;
F_71 ( & V_2 -> V_100 ) ;
V_24 = F_64 ( V_2 , & V_103 -> V_48 , & V_17 , & V_36 ) ;
if ( V_24 < 0 )
goto V_101;
if ( V_24 ) {
V_22 = V_17 -> V_20 [ V_36 ] . V_22 ;
if ( V_22 > V_103 -> V_108 ) {
V_24 = - V_79 ;
goto V_101;
}
V_103 -> V_20 [ V_103 -> V_105 ++ ] = V_17 -> V_20 [ V_36 ] ;
V_103 -> V_106 += 1 ;
V_3 = V_17 -> V_20 [ V_36 ] . V_3 ;
V_4 = F_21 ( V_17 -> V_20 [ V_36 ] . V_4 + V_22 , 8 ) ;
}
while ( 1 ) {
struct V_18 * V_19 ;
union V_64 * V_48 ;
unsigned int V_109 ;
V_24 = F_54 ( V_2 , & V_17 , & V_36 ) ;
if ( V_24 )
goto V_101;
V_19 = & V_17 -> V_20 [ V_36 ] ;
V_48 = & V_19 -> V_48 ;
if ( F_76 ( V_2 , V_48 ) != F_76 ( V_2 , & V_103 -> V_48 ) ||
F_45 ( V_2 , V_48 ) != V_110 ) {
V_24 = - V_78 ;
goto V_101;
}
if ( V_3 < 0 ) {
V_3 = V_19 -> V_3 ;
V_4 = F_21 ( V_19 -> V_4 + V_19 -> V_22 , 8 ) ;
V_22 = V_19 -> V_22 ;
if ( V_22 > V_103 -> V_108 ) {
V_24 = - V_79 ;
goto V_101;
}
} else {
if ( V_19 -> V_3 != V_3 || V_19 -> V_4 != V_4 )
goto V_101;
V_4 += F_21 ( V_19 -> V_22 , 8 ) ;
V_22 = F_21 ( V_22 , 8 ) + V_19 -> V_22 ;
if ( V_22 > V_103 -> V_108 )
goto V_101;
}
V_109 = F_75 ( V_2 , V_48 ) ;
V_103 -> V_106 += ( V_109 - V_104 - 1 ) ;
if ( V_103 -> V_106 >= V_111 )
goto V_101;
V_104 = V_109 ;
V_103 -> V_20 [ V_103 -> V_105 ++ ] = * V_19 ;
V_103 -> V_106 += 1 ;
if ( V_103 -> V_105 >= V_111 )
goto V_101;
if ( V_103 -> V_106 >= V_111 )
goto V_101;
}
V_101:
if ( V_24 == - V_78 ) {
V_103 -> V_107 = 1 ;
V_24 = 0 ;
}
V_103 -> V_95 = V_2 -> V_95 ;
F_72 ( & V_2 -> V_100 ) ;
if ( V_24 )
return V_24 ;
if ( V_103 -> V_106 > V_111 )
V_103 -> V_106 = V_111 ;
if ( V_112 == 1 ||
! ( V_103 -> V_106 & ( V_112 - 1 ) ) )
return 0 ;
if ( V_103 -> V_107 ) {
V_103 -> V_106 += V_112 - 1 ;
return 0 ;
}
V_104 = F_75 ( V_2 , & V_103 -> V_48 ) + V_103 -> V_106 ;
V_104 &= ~ ( V_112 - 1 ) ;
while ( V_103 -> V_105 ) {
if ( F_75 ( V_2 , & V_103 -> V_20 [ V_103 -> V_105 - 1 ] . V_48 ) < V_104 )
break;
V_103 -> V_105 -= 1 ;
}
return 0 ;
}
static int F_77 ( struct V_113 * V_114 , void * V_49 , int V_22 , int V_3 ,
int V_4 )
{
const struct V_1 * V_2 = V_114 -> V_2 ;
int V_115 , V_116 ;
F_37 ( L_12 , V_3 , V_4 , V_22 ) ;
F_17 ( V_114 && V_3 >= 0 && V_3 < V_2 -> V_117 && V_4 >= 0 ) ;
F_17 ( ! ( V_4 & 7 ) && V_4 < V_2 -> V_118 ) ;
F_17 ( V_4 + V_22 <= V_2 -> V_118 ) ;
F_78 ( & V_114 -> V_119 ) ;
V_116 = ( V_3 == V_114 -> V_3 && V_4 + V_22 > V_114 -> V_4 ) ;
if ( ! V_116 ) {
F_79 ( & V_114 -> V_119 ) ;
return F_39 ( V_2 -> V_55 , V_3 , V_49 , V_4 , V_22 ) ;
}
V_115 = V_114 -> V_4 - V_4 ;
if ( V_115 < 0 )
V_115 = 0 ;
memcpy ( V_49 + V_115 , V_114 -> V_49 + V_4 + V_115 - V_114 -> V_4 , V_22 - V_115 ) ;
F_79 ( & V_114 -> V_119 ) ;
if ( V_115 > 0 )
return F_39 ( V_2 -> V_55 , V_3 , V_49 , V_4 , V_115 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , void * V_49 ,
struct V_18 * V_19 )
{
union V_64 V_120 ;
struct V_51 * V_52 = V_49 ;
int V_24 , V_22 ;
if ( V_52 -> V_58 != V_59 ) {
F_5 ( L_13 ,
V_52 -> V_58 , V_59 ) ;
goto V_121;
}
V_24 = F_81 ( V_2 , V_49 , V_19 -> V_3 , V_19 -> V_4 , 0 , 0 ) ;
if ( V_24 ) {
F_5 ( L_14 , V_59 ) ;
goto V_101;
}
V_22 = F_40 ( V_52 -> V_22 ) ;
if ( V_22 != V_19 -> V_22 ) {
F_5 ( L_15 , V_22 , V_19 -> V_22 ) ;
goto V_121;
}
F_46 ( V_2 , V_49 + V_122 , & V_120 ) ;
if ( ! F_82 ( V_2 , & V_19 -> V_48 , & V_120 ) ) {
F_5 ( L_16 ,
V_19 -> V_3 , V_19 -> V_4 ) ;
F_43 ( L_17 ,
F_44 ( & V_19 -> V_48 ) , F_83 ( & V_120 ) ) ;
goto V_121;
}
return 0 ;
V_121:
V_24 = - V_79 ;
V_101:
F_5 ( L_18 , V_19 -> V_3 , V_19 -> V_4 ) ;
F_31 ( V_2 , V_49 ) ;
F_30 () ;
return V_24 ;
}
int F_84 ( struct V_1 * V_2 , struct V_102 * V_103 )
{
int V_3 = V_103 -> V_20 [ 0 ] . V_3 , V_4 = V_103 -> V_20 [ 0 ] . V_4 , V_22 , V_24 , V_35 ;
struct V_113 * V_114 ;
void * V_49 ;
V_22 = V_103 -> V_20 [ V_103 -> V_105 - 1 ] . V_4 ;
V_22 += V_103 -> V_20 [ V_103 -> V_105 - 1 ] . V_22 - V_4 ;
if ( V_22 > V_103 -> V_108 ) {
F_5 ( L_19 , V_103 -> V_108 , V_22 ) ;
return - V_79 ;
}
V_114 = F_73 ( V_2 , V_3 ) ;
if ( V_114 )
V_24 = F_77 ( V_114 , V_103 -> V_49 , V_22 , V_3 , V_4 ) ;
else
V_24 = F_39 ( V_2 -> V_55 , V_3 , V_103 -> V_49 , V_4 , V_22 ) ;
if ( F_68 ( V_2 , V_3 , V_103 -> V_95 ) )
return - V_123 ;
if ( V_24 && V_24 != - V_124 ) {
F_5 ( L_20 ,
V_3 , V_4 , V_24 ) ;
F_30 () ;
F_43 ( L_21 , F_44 ( & V_103 -> V_48 ) ) ;
return V_24 ;
}
V_49 = V_103 -> V_49 ;
for ( V_35 = 0 ; V_35 < V_103 -> V_105 ; V_35 ++ ) {
V_24 = F_80 ( V_2 , V_49 , & V_103 -> V_20 [ V_35 ] ) ;
if ( V_24 )
return V_24 ;
V_49 = V_49 + F_21 ( V_103 -> V_20 [ V_35 ] . V_22 , 8 ) ;
}
return 0 ;
}
static int F_85 ( struct V_1 * V_2 , const union V_64 * V_48 ,
void * V_43 , const struct V_68 * V_69 )
{
int V_96 , V_36 , V_24 ;
struct V_16 * V_17 ;
F_43 ( L_22 , V_69 -> V_22 , V_69 -> V_72 , F_44 ( V_48 ) ) ;
F_71 ( & V_2 -> V_100 ) ;
V_96 = F_64 ( V_2 , V_48 , & V_17 , & V_36 ) ;
if ( ! V_96 ) {
V_24 = - V_78 ;
goto V_125;
} else if ( V_96 < 0 ) {
V_24 = V_96 ;
goto V_125;
}
F_17 ( V_36 >= 0 ) ;
V_24 = F_57 ( V_2 , V_48 , & V_17 , & V_36 , V_69 ) ;
F_43 ( L_23 , V_24 , V_17 , V_36 ) ;
if ( F_3 ( V_24 < 0 ) )
goto V_125;
if ( V_24 == 0 ) {
V_24 = - V_78 ;
goto V_125;
}
V_24 = F_34 ( V_2 , & V_17 -> V_20 [ V_36 ] , V_43 ) ;
V_125:
F_72 ( & V_2 -> V_100 ) ;
return V_24 ;
}
int F_86 ( struct V_1 * V_2 , const union V_64 * V_48 ,
void * V_43 , const struct V_68 * V_69 )
{
int V_24 , V_22 ;
const struct V_45 * V_46 = V_43 ;
V_24 = F_87 ( V_2 , V_48 , V_43 ) ;
if ( V_24 )
return V_24 ;
V_22 = F_50 ( V_46 -> V_70 ) ;
if ( V_69 -> V_22 == V_22 && ! memcmp ( V_46 -> V_72 , V_69 -> V_72 , V_22 ) )
return 0 ;
return F_85 ( V_2 , V_48 , V_43 , V_69 ) ;
}
static void F_88 ( const struct V_1 * V_2 ,
struct V_16 * V_17 )
{
union V_64 * V_48 , * V_120 ;
F_17 ( V_17 -> V_10 ) ;
F_17 ( V_17 -> V_21 == 0 ) ;
V_48 = & V_17 -> V_20 [ 0 ] . V_48 ;
V_120 = & V_17 -> V_10 -> V_20 [ 0 ] . V_48 ;
while ( F_47 ( V_2 , V_48 , V_120 ) < 0 ) {
F_89 ( V_2 , V_48 , V_120 ) ;
V_17 = V_17 -> V_10 ;
V_17 -> V_126 = 1 ;
if ( ! V_17 -> V_10 || V_17 -> V_21 )
break;
V_120 = & V_17 -> V_10 -> V_20 [ 0 ] . V_48 ;
}
}
static void F_90 ( struct V_16 * V_17 ,
const struct V_18 * V_19 , int V_36 )
{
int V_35 ;
F_17 ( F_63 ( V_17 ) ) ;
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
V_17 -> V_126 = 1 ;
}
static int F_91 ( struct V_1 * V_2 , struct V_16 * V_17 ,
struct V_18 * V_19 , int V_36 )
{
struct V_16 * V_27 , * V_127 , * V_77 ;
int V_35 , V_128 , V_129 , V_130 = 0 ;
union V_64 * V_48 = & V_19 -> V_48 , * V_120 ;
F_17 ( V_36 >= 0 && V_36 <= V_2 -> V_131 ) ;
V_99:
V_77 = V_17 -> V_10 ;
if ( V_17 -> V_37 < V_2 -> V_131 ) {
F_17 ( V_36 != V_2 -> V_131 ) ;
F_43 ( L_24 , V_36 , V_17 -> V_34 ,
F_44 ( V_48 ) ) ;
F_90 ( V_17 , V_19 , V_36 ) ;
if ( V_36 == 0 && V_77 && V_17 -> V_21 == 0 )
F_88 ( V_2 , V_17 ) ;
return 0 ;
}
F_43 ( L_25 , V_17 -> V_34 , F_44 ( V_48 ) ) ;
if ( V_17 -> V_126 )
F_10 ( V_2 , V_17 ) ;
V_27 = F_92 ( V_2 -> V_28 , V_11 ) ;
if ( ! V_27 )
return - V_12 ;
V_27 -> V_10 = V_77 ;
V_27 -> V_34 = V_17 -> V_34 ;
if ( V_17 -> V_34 == 0 && F_45 ( V_2 , V_48 ) == V_110 ) {
if ( V_36 == V_2 -> V_131 ) {
V_120 = & V_17 -> V_20 [ V_36 - 1 ] . V_48 ;
if ( F_76 ( V_2 , V_120 ) == F_76 ( V_2 , V_48 ) &&
F_45 ( V_2 , V_120 ) == V_110 )
V_130 = 1 ;
} else
goto V_132;
} else if ( V_130 && V_36 != V_2 -> V_131 ) {
V_130 = 0 ;
V_132:
if ( V_36 >= ( V_2 -> V_131 + 1 ) / 2 ) {
V_120 = & V_17 -> V_20 [ 0 ] . V_48 ;
if ( F_76 ( V_2 , V_120 ) == F_76 ( V_2 , V_48 ) &&
F_45 ( V_2 , V_120 ) == V_110 ) {
V_120 = & V_17 -> V_20 [ V_36 ] . V_48 ;
if ( F_76 ( V_2 , V_120 ) != F_76 ( V_2 , V_48 ) ||
F_45 ( V_2 , V_120 ) != V_110 ) {
V_128 = V_36 ;
V_129 = V_2 -> V_131 - V_128 ;
V_127 = V_17 ;
goto V_133;
}
}
}
}
if ( V_130 ) {
V_128 = V_2 -> V_131 ;
V_129 = 0 ;
} else {
V_128 = ( V_2 -> V_131 + 1 ) / 2 ;
V_129 = V_2 -> V_131 - V_128 ;
}
if ( V_36 < V_128 ) {
V_127 = V_17 ;
V_129 += 1 ;
V_128 -= 1 ;
} else {
V_127 = V_27 ;
V_36 -= V_128 ;
if ( V_27 -> V_34 != 0 )
V_19 -> V_17 -> V_10 = V_27 ;
}
V_133:
F_15 ( V_30 , & V_27 -> V_31 ) ;
F_19 ( & V_2 -> V_38 ) ;
V_27 -> V_37 = V_129 ;
V_17 -> V_37 = V_128 ;
F_43 ( L_26 , V_129 , V_128 ) ;
for ( V_35 = 0 ; V_35 < V_129 ; V_35 ++ ) {
V_27 -> V_20 [ V_35 ] = V_17 -> V_20 [ V_128 + V_35 ] ;
if ( V_27 -> V_34 != 0 )
if ( V_27 -> V_20 [ V_35 ] . V_17 ) {
V_27 -> V_20 [ V_35 ] . V_17 -> V_10 = V_27 ;
V_27 -> V_20 [ V_35 ] . V_17 -> V_21 = V_35 ;
}
}
F_43 ( L_27 , V_36 , V_27 -> V_34 , F_44 ( V_48 ) ) ;
F_90 ( V_127 , V_19 , V_36 ) ;
if ( V_77 ) {
if ( V_36 == 0 && V_127 == V_17 && V_17 -> V_21 == 0 )
F_88 ( V_2 , V_17 ) ;
V_36 = V_17 -> V_21 + 1 ;
V_19 -> V_48 = V_27 -> V_20 [ 0 ] . V_48 ;
V_19 -> V_17 = V_27 ;
V_19 -> V_3 = 0 ;
V_19 -> V_4 = 0 ;
V_19 -> V_22 = 0 ;
V_17 = V_77 ;
goto V_99;
}
F_43 ( L_28 , V_17 -> V_34 + 1 ) ;
V_127 = F_92 ( V_2 -> V_28 , V_11 ) ;
if ( ! V_127 )
return - V_12 ;
V_127 -> V_37 = 2 ;
V_127 -> V_34 = V_17 -> V_34 + 1 ;
F_15 ( V_30 , & V_127 -> V_31 ) ;
F_19 ( & V_2 -> V_38 ) ;
V_127 -> V_20 [ 0 ] . V_48 = V_17 -> V_20 [ 0 ] . V_48 ;
V_127 -> V_20 [ 0 ] . V_17 = V_17 ;
V_127 -> V_20 [ 0 ] . V_3 = V_2 -> V_23 . V_3 ;
V_127 -> V_20 [ 0 ] . V_4 = V_2 -> V_23 . V_4 ;
V_127 -> V_20 [ 0 ] . V_22 = V_2 -> V_23 . V_22 ;
V_127 -> V_20 [ 1 ] . V_48 = V_27 -> V_20 [ 0 ] . V_48 ;
V_127 -> V_20 [ 1 ] . V_17 = V_27 ;
V_2 -> V_23 . V_3 = 0 ;
V_2 -> V_23 . V_4 = 0 ;
V_2 -> V_23 . V_22 = 0 ;
V_2 -> V_23 . V_17 = V_127 ;
V_27 -> V_10 = V_127 ;
V_27 -> V_21 = 1 ;
V_17 -> V_10 = V_127 ;
V_17 -> V_21 = 0 ;
return 0 ;
}
int F_93 ( struct V_1 * V_2 , const union V_64 * V_48 , int V_3 ,
int V_4 , int V_22 )
{
int V_96 , V_36 , V_24 = 0 ;
struct V_16 * V_17 ;
F_71 ( & V_2 -> V_100 ) ;
F_43 ( L_29 , V_3 , V_4 , V_22 , F_44 ( V_48 ) ) ;
V_96 = F_67 ( V_2 , V_48 , & V_17 , & V_36 ) ;
if ( ! V_96 ) {
struct V_18 V_19 ;
V_19 . V_17 = NULL ;
V_19 . V_3 = V_3 ;
V_19 . V_4 = V_4 ;
V_19 . V_22 = V_22 ;
F_89 ( V_2 , V_48 , & V_19 . V_48 ) ;
V_24 = F_91 ( V_2 , V_17 , & V_19 , V_36 + 1 ) ;
} else if ( V_96 == 1 ) {
struct V_18 * V_19 = & V_17 -> V_20 [ V_36 ] ;
F_33 ( V_19 ) ;
V_24 = F_22 ( V_2 , V_19 -> V_3 , V_19 -> V_22 ) ;
V_19 -> V_3 = V_3 ;
V_19 -> V_4 = V_4 ;
V_19 -> V_22 = V_22 ;
} else
V_24 = V_96 ;
if ( ! V_24 )
V_24 = F_94 ( V_2 , 0 ) ;
F_72 ( & V_2 -> V_100 ) ;
return V_24 ;
}
int F_95 ( struct V_1 * V_2 , const union V_64 * V_48 ,
int V_134 , int V_135 , int V_3 , int V_4 , int V_22 )
{
int V_96 , V_36 , V_24 = 0 ;
struct V_16 * V_17 ;
F_71 ( & V_2 -> V_100 ) ;
F_43 ( L_30 , V_134 ,
V_135 , V_3 , V_4 , V_22 , F_44 ( V_48 ) ) ;
V_96 = F_67 ( V_2 , V_48 , & V_17 , & V_36 ) ;
if ( V_96 < 0 ) {
V_24 = V_96 ;
goto V_125;
}
if ( V_96 == 1 ) {
struct V_18 * V_19 = & V_17 -> V_20 [ V_36 ] ;
V_96 = 0 ;
if ( V_19 -> V_3 == V_134 && V_19 -> V_4 == V_135 ) {
F_33 ( V_19 ) ;
V_24 = F_22 ( V_2 , V_19 -> V_3 , V_19 -> V_22 ) ;
if ( V_24 )
goto V_125;
V_19 -> V_3 = V_3 ;
V_19 -> V_4 = V_4 ;
V_19 -> V_22 = V_22 ;
V_96 = 1 ;
} else if ( F_28 ( V_2 , V_48 ) ) {
V_96 = F_61 ( V_2 , V_48 , & V_17 , & V_36 ,
V_134 , V_135 ) ;
F_43 ( L_31 ,
V_96 , V_17 , V_36 , V_134 , V_135 ) ;
if ( V_96 < 0 ) {
V_24 = V_96 ;
goto V_125;
}
if ( V_96 ) {
if ( V_17 -> V_29 || ! F_63 ( V_17 ) ) {
V_17 = F_62 ( V_2 , V_17 ) ;
if ( F_26 ( V_17 ) ) {
V_24 = F_55 ( V_17 ) ;
goto V_125;
}
}
V_19 = & V_17 -> V_20 [ V_36 ] ;
F_33 ( V_19 ) ;
V_24 = F_22 ( V_2 , V_19 -> V_3 ,
V_19 -> V_22 ) ;
if ( V_24 )
goto V_125;
V_19 -> V_3 = V_3 ;
V_19 -> V_4 = V_4 ;
V_19 -> V_22 = V_22 ;
}
}
}
if ( ! V_96 )
V_24 = F_22 ( V_2 , V_3 , V_22 ) ;
if ( ! V_24 )
V_24 = F_94 ( V_2 , 0 ) ;
V_125:
F_72 ( & V_2 -> V_100 ) ;
return V_24 ;
}
int F_96 ( struct V_1 * V_2 , const union V_64 * V_48 ,
int V_3 , int V_4 , int V_22 , const struct V_68 * V_69 )
{
int V_96 , V_36 , V_24 = 0 ;
struct V_16 * V_17 ;
F_71 ( & V_2 -> V_100 ) ;
F_43 ( L_32 , V_3 , V_4 , V_69 -> V_22 , V_69 -> V_72 ,
F_44 ( V_48 ) ) ;
V_96 = F_67 ( V_2 , V_48 , & V_17 , & V_36 ) ;
if ( V_96 < 0 ) {
V_24 = V_96 ;
goto V_125;
}
if ( V_96 == 1 ) {
if ( V_2 -> V_67 )
V_96 = F_59 ( V_2 , V_48 , & V_17 , & V_36 ,
V_69 , 1 ) ;
else
V_96 = F_57 ( V_2 , V_48 , & V_17 , & V_36 , V_69 ) ;
F_43 ( L_23 , V_96 , V_17 , V_36 ) ;
if ( V_96 < 0 ) {
V_24 = V_96 ;
goto V_125;
}
if ( V_17 -> V_29 || ! F_63 ( V_17 ) ) {
V_17 = F_62 ( V_2 , V_17 ) ;
if ( F_26 ( V_17 ) ) {
V_24 = F_55 ( V_17 ) ;
goto V_125;
}
}
if ( V_96 == 1 ) {
struct V_18 * V_19 = & V_17 -> V_20 [ V_36 ] ;
F_33 ( V_19 ) ;
V_24 = F_22 ( V_2 , V_19 -> V_3 , V_19 -> V_22 ) ;
V_19 -> V_3 = V_3 ;
V_19 -> V_4 = V_4 ;
V_19 -> V_22 = V_22 ;
goto V_125;
}
}
if ( ! V_96 ) {
struct V_18 V_19 ;
V_19 . V_17 = NULL ;
V_19 . V_3 = V_3 ;
V_19 . V_4 = V_4 ;
V_19 . V_22 = V_22 ;
F_89 ( V_2 , V_48 , & V_19 . V_48 ) ;
V_24 = F_91 ( V_2 , V_17 , & V_19 , V_36 + 1 ) ;
if ( V_24 )
goto V_125;
if ( V_2 -> V_67 ) {
struct V_68 V_136 = { . V_22 = 0 , . V_72 = L_33 } ;
V_24 = F_94 ( V_2 , 0 ) ;
F_72 ( & V_2 -> V_100 ) ;
if ( V_24 )
return V_24 ;
return F_97 ( V_2 , V_48 , & V_136 ) ;
}
}
V_125:
if ( ! V_24 )
V_24 = F_94 ( V_2 , 0 ) ;
F_72 ( & V_2 -> V_100 ) ;
return V_24 ;
}
static int F_98 ( struct V_1 * V_2 , struct V_16 * V_17 , int V_36 )
{
struct V_18 * V_19 ;
struct V_16 * V_77 ;
int V_35 , V_24 ;
F_17 ( V_17 -> V_34 == 0 ) ;
F_17 ( V_36 >= 0 && V_36 < V_2 -> V_131 ) ;
F_43 ( L_34 , F_44 ( & V_17 -> V_20 [ V_36 ] . V_48 ) ) ;
V_19 = & V_17 -> V_20 [ V_36 ] ;
F_33 ( V_19 ) ;
V_24 = F_22 ( V_2 , V_19 -> V_3 , V_19 -> V_22 ) ;
if ( V_24 ) {
F_99 ( V_2 , V_17 ) ;
return V_24 ;
}
for ( V_35 = V_36 ; V_35 < V_17 -> V_37 - 1 ; V_35 ++ )
V_17 -> V_20 [ V_35 ] = V_17 -> V_20 [ V_35 + 1 ] ;
V_17 -> V_37 -= 1 ;
if ( V_17 -> V_37 > 0 )
return 0 ;
do {
F_17 ( ! F_18 ( V_33 , & V_17 -> V_31 ) ) ;
F_17 ( F_63 ( V_17 ) ) ;
V_77 = V_17 -> V_10 ;
V_36 = V_17 -> V_21 ;
F_25 ( & V_2 -> V_38 ) ;
V_24 = F_9 ( V_2 , V_17 ) ;
if ( V_24 )
return V_24 ;
if ( V_17 -> V_29 ) {
F_15 ( V_33 , & V_17 -> V_31 ) ;
F_19 ( & V_2 -> V_41 ) ;
F_19 ( & V_42 ) ;
} else
F_6 ( V_17 ) ;
V_17 = V_77 ;
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
V_77 = V_17 ;
V_19 = & V_17 -> V_20 [ 0 ] ;
V_17 = F_52 ( V_2 , V_17 , 0 ) ;
if ( F_26 ( V_17 ) )
return F_55 ( V_17 ) ;
V_17 = F_23 ( V_2 , V_19 ) ;
if ( F_26 ( V_17 ) )
return F_55 ( V_17 ) ;
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
F_17 ( ! F_18 ( V_33 ,
& V_77 -> V_31 ) ) ;
F_17 ( F_18 ( V_30 , & V_77 -> V_31 ) ) ;
F_25 ( & V_2 -> V_38 ) ;
if ( V_77 -> V_29 ) {
F_15 ( V_33 , & V_77 -> V_31 ) ;
F_19 ( & V_2 -> V_41 ) ;
F_19 ( & V_42 ) ;
} else
F_6 ( V_77 ) ;
}
}
return 0 ;
}
int F_100 ( struct V_1 * V_2 , const union V_64 * V_48 )
{
int V_96 , V_36 , V_24 = 0 ;
struct V_16 * V_17 ;
F_71 ( & V_2 -> V_100 ) ;
F_43 ( L_21 , F_44 ( V_48 ) ) ;
V_96 = F_67 ( V_2 , V_48 , & V_17 , & V_36 ) ;
if ( V_96 < 0 ) {
V_24 = V_96 ;
goto V_125;
}
if ( V_96 == 1 )
V_24 = F_98 ( V_2 , V_17 , V_36 ) ;
if ( ! V_24 )
V_24 = F_94 ( V_2 , 0 ) ;
V_125:
F_72 ( & V_2 -> V_100 ) ;
return V_24 ;
}
int F_97 ( struct V_1 * V_2 , const union V_64 * V_48 ,
const struct V_68 * V_69 )
{
int V_36 , V_24 ;
struct V_16 * V_17 ;
F_71 ( & V_2 -> V_100 ) ;
F_43 ( L_35 , V_69 -> V_22 , V_69 -> V_72 , F_44 ( V_48 ) ) ;
V_24 = F_67 ( V_2 , V_48 , & V_17 , & V_36 ) ;
if ( V_24 < 0 )
goto V_125;
if ( V_24 ) {
if ( V_2 -> V_67 )
V_24 = F_59 ( V_2 , V_48 , & V_17 , & V_36 ,
V_69 , 0 ) ;
else
V_24 = F_57 ( V_2 , V_48 , & V_17 , & V_36 , V_69 ) ;
F_43 ( L_23 , V_24 , V_17 , V_36 ) ;
if ( V_24 < 0 )
goto V_125;
if ( V_24 ) {
if ( V_17 -> V_29 || ! F_63 ( V_17 ) ) {
V_17 = F_62 ( V_2 , V_17 ) ;
if ( F_26 ( V_17 ) ) {
V_24 = F_55 ( V_17 ) ;
goto V_125;
}
}
V_24 = F_98 ( V_2 , V_17 , V_36 ) ;
}
}
V_125:
if ( ! V_24 )
V_24 = F_94 ( V_2 , 0 ) ;
F_72 ( & V_2 -> V_100 ) ;
return V_24 ;
}
static int F_101 ( struct V_1 * V_2 , union V_64 * V_48 ,
union V_64 * V_137 , union V_64 * V_138 )
{
if ( F_47 ( V_2 , V_48 , V_137 ) < 0 )
return 0 ;
if ( F_47 ( V_2 , V_48 , V_138 ) > 0 )
return 0 ;
return 1 ;
}
int F_102 ( struct V_1 * V_2 , union V_64 * V_137 ,
union V_64 * V_138 )
{
int V_35 , V_36 , V_139 , V_24 = 0 ;
struct V_16 * V_17 ;
union V_64 * V_48 ;
F_71 ( & V_2 -> V_100 ) ;
while ( 1 ) {
V_24 = F_64 ( V_2 , V_137 , & V_17 , & V_36 ) ;
if ( V_24 < 0 )
goto V_125;
if ( V_24 )
V_48 = V_137 ;
else {
V_24 = F_54 ( V_2 , & V_17 , & V_36 ) ;
if ( V_24 == - V_78 ) {
V_24 = 0 ;
goto V_125;
}
if ( V_24 < 0 )
goto V_125;
V_48 = & V_17 -> V_20 [ V_36 ] . V_48 ;
if ( ! F_101 ( V_2 , V_48 , V_137 , V_138 ) ) {
V_24 = 0 ;
goto V_125;
}
}
if ( V_17 -> V_29 || ! F_63 ( V_17 ) ) {
V_17 = F_62 ( V_2 , V_17 ) ;
if ( F_26 ( V_17 ) ) {
V_24 = F_55 ( V_17 ) ;
goto V_125;
}
}
for ( V_35 = V_36 + 1 , V_139 = 0 ; V_35 < V_17 -> V_37 ; V_35 ++ , V_139 ++ ) {
V_48 = & V_17 -> V_20 [ V_35 ] . V_48 ;
if ( ! F_101 ( V_2 , V_48 , V_137 , V_138 ) )
break;
F_33 ( & V_17 -> V_20 [ V_35 ] ) ;
V_24 = F_22 ( V_2 , V_17 -> V_20 [ V_35 ] . V_3 ,
V_17 -> V_20 [ V_35 ] . V_22 ) ;
if ( V_24 ) {
F_99 ( V_2 , V_17 ) ;
goto V_125;
}
F_43 ( L_36 , F_44 ( V_48 ) ) ;
}
if ( V_139 ) {
for ( V_35 = V_36 + 1 + V_139 ; V_35 < V_17 -> V_37 ; V_35 ++ )
V_17 -> V_20 [ V_35 - V_139 ] = V_17 -> V_20 [ V_35 ] ;
V_17 -> V_37 -= V_139 ;
}
V_24 = F_98 ( V_2 , V_17 , V_36 ) ;
if ( V_24 )
goto V_125;
}
V_125:
if ( ! V_24 )
V_24 = F_94 ( V_2 , 0 ) ;
F_72 ( & V_2 -> V_100 ) ;
return V_24 ;
}
int F_103 ( struct V_1 * V_2 , T_2 V_140 )
{
union V_64 V_120 , V_141 ;
struct V_45 * V_142 , * V_143 = NULL ;
struct V_68 V_69 = { . V_72 = NULL } ;
F_43 ( L_37 , ( unsigned long ) V_140 ) ;
F_104 ( V_2 , & V_120 , V_140 ) ;
while ( 1 ) {
T_2 V_144 ;
int V_24 ;
V_142 = F_105 ( V_2 , & V_120 , & V_69 ) ;
if ( F_26 ( V_142 ) ) {
V_24 = F_55 ( V_142 ) ;
if ( V_24 == - V_78 )
break;
return V_24 ;
}
V_144 = F_106 ( V_142 -> V_140 ) ;
F_43 ( L_38 , V_142 -> V_72 ,
( unsigned long ) V_144 ) ;
V_69 . V_72 = V_142 -> V_72 ;
V_69 . V_22 = F_50 ( V_142 -> V_70 ) ;
V_24 = F_97 ( V_2 , & V_120 , & V_69 ) ;
if ( V_24 ) {
F_6 ( V_142 ) ;
return V_24 ;
}
F_107 ( V_2 , & V_120 , V_144 ) ;
F_108 ( V_2 , & V_141 , V_144 ) ;
V_24 = F_102 ( V_2 , & V_120 , & V_141 ) ;
if ( V_24 ) {
F_6 ( V_142 ) ;
return V_24 ;
}
F_6 ( V_143 ) ;
V_143 = V_142 ;
F_46 ( V_2 , & V_142 -> V_48 , & V_120 ) ;
}
F_6 ( V_143 ) ;
F_107 ( V_2 , & V_120 , V_140 ) ;
F_108 ( V_2 , & V_141 , V_140 ) ;
return F_102 ( V_2 , & V_120 , & V_141 ) ;
}
struct V_45 * F_105 ( struct V_1 * V_2 ,
union V_64 * V_48 ,
const struct V_68 * V_69 )
{
int V_36 , V_24 , type = F_45 ( V_2 , V_48 ) ;
struct V_16 * V_17 ;
struct V_45 * V_46 ;
struct V_18 * V_19 ;
union V_64 * V_145 ;
F_43 ( L_39 , V_69 -> V_72 ? ( char * ) V_69 -> V_72 : L_40 , F_44 ( V_48 ) ) ;
F_17 ( F_28 ( V_2 , V_48 ) ) ;
F_71 ( & V_2 -> V_100 ) ;
V_24 = F_64 ( V_2 , V_48 , & V_17 , & V_36 ) ;
if ( F_3 ( V_24 < 0 ) )
goto V_125;
if ( V_69 -> V_72 ) {
if ( V_24 ) {
V_24 = F_57 ( V_2 , V_48 , & V_17 , & V_36 , V_69 ) ;
F_43 ( L_23 ,
V_24 , V_17 , V_36 ) ;
if ( F_3 ( V_24 < 0 ) )
goto V_125;
}
V_24 = F_54 ( V_2 , & V_17 , & V_36 ) ;
if ( F_3 ( V_24 ) )
goto V_125;
} else {
if ( ! V_24 ) {
V_24 = F_54 ( V_2 , & V_17 , & V_36 ) ;
if ( V_24 )
goto V_125;
}
}
V_19 = & V_17 -> V_20 [ V_36 ] ;
V_46 = F_2 ( V_19 -> V_22 , V_11 ) ;
if ( F_3 ( ! V_46 ) ) {
V_24 = - V_12 ;
goto V_125;
}
V_145 = & V_19 -> V_48 ;
if ( F_76 ( V_2 , V_145 ) != F_76 ( V_2 , V_48 ) ||
F_45 ( V_2 , V_145 ) != type ) {
V_24 = - V_78 ;
goto V_71;
}
V_24 = F_34 ( V_2 , V_19 , V_46 ) ;
if ( F_3 ( V_24 ) )
goto V_71;
F_72 ( & V_2 -> V_100 ) ;
return V_46 ;
V_71:
F_6 ( V_46 ) ;
V_125:
F_72 ( & V_2 -> V_100 ) ;
return F_14 ( V_24 ) ;
}
static void F_109 ( struct V_1 * V_2 )
{
struct V_16 * V_29 ;
if ( ! V_2 -> V_29 )
return;
F_17 ( V_2 -> V_146 == V_147 ) ;
V_29 = V_2 -> V_29 ;
do {
struct V_16 * V_17 = V_29 ;
V_29 = V_29 -> V_29 ;
if ( F_18 ( V_33 , & V_17 -> V_31 ) )
F_6 ( V_17 ) ;
} while ( V_29 && V_29 != V_2 -> V_29 );
}
void F_110 ( struct V_1 * V_2 )
{
F_109 ( V_2 ) ;
if ( V_2 -> V_23 . V_17 ) {
long V_36 ;
F_111 ( V_2 -> V_23 . V_17 ) ;
V_36 = F_112 ( & V_2 -> V_41 ) ;
F_113 ( V_36 , & V_42 ) ;
}
F_6 ( V_2 -> V_148 ) ;
F_6 ( V_2 -> V_149 ) ;
F_11 ( V_2 ) ;
}
static struct V_16 * F_114 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
int V_34 = V_17 -> V_34 ;
while ( 1 ) {
int V_36 = V_17 -> V_21 - 1 ;
V_17 = V_17 -> V_10 ;
if ( ! V_17 )
return NULL ;
if ( V_36 >= 0 ) {
V_17 = F_52 ( V_2 , V_17 , V_36 ) ;
if ( F_26 ( V_17 ) )
return V_17 ;
while ( V_17 -> V_34 != V_34 ) {
V_36 = V_17 -> V_37 - 1 ;
V_17 = F_52 ( V_2 , V_17 , V_36 ) ;
if ( F_26 ( V_17 ) )
return V_17 ;
}
break;
}
}
return V_17 ;
}
static struct V_16 * F_115 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
int V_34 = V_17 -> V_34 ;
while ( 1 ) {
int V_36 = V_17 -> V_21 + 1 ;
V_17 = V_17 -> V_10 ;
if ( ! V_17 )
return NULL ;
if ( V_36 < V_17 -> V_37 ) {
V_17 = F_52 ( V_2 , V_17 , V_36 ) ;
if ( F_26 ( V_17 ) )
return V_17 ;
while ( V_17 -> V_34 != V_34 ) {
V_17 = F_52 ( V_2 , V_17 , 0 ) ;
if ( F_26 ( V_17 ) )
return V_17 ;
}
break;
}
}
return V_17 ;
}
static struct V_16 * F_116 ( struct V_1 * V_2 ,
union V_64 * V_48 , int V_34 ,
int V_3 , int V_4 )
{
struct V_16 * V_17 , * V_27 ;
int V_36 , V_76 ;
F_17 ( F_45 ( V_2 , V_48 ) < V_91 ) ;
if ( V_34 < 0 )
return F_14 ( - V_79 ) ;
V_17 = V_2 -> V_23 . V_17 ;
if ( ! V_17 ) {
V_17 = F_53 ( V_2 , & V_2 -> V_23 , NULL , 0 ) ;
if ( F_26 ( V_17 ) )
return V_17 ;
}
if ( V_2 -> V_23 . V_3 == V_3 && V_2 -> V_23 . V_4 == V_4 )
return V_17 ;
if ( V_34 >= V_17 -> V_34 )
return NULL ;
while ( 1 ) {
F_66 ( V_2 , V_17 , V_48 , & V_36 ) ;
if ( V_36 < 0 ) {
V_17 = F_114 ( V_2 , V_17 ) ;
if ( ! V_17 )
return NULL ;
if ( F_26 ( V_17 ) )
return V_17 ;
F_66 ( V_2 , V_17 , V_48 , & V_36 ) ;
F_17 ( V_36 >= 0 ) ;
}
if ( V_17 -> V_34 == V_34 + 1 )
break;
V_17 = F_52 ( V_2 , V_17 , V_36 ) ;
if ( F_26 ( V_17 ) )
return V_17 ;
}
if ( V_17 -> V_20 [ V_36 ] . V_3 == V_3 && V_17 -> V_20 [ V_36 ] . V_4 == V_4 )
return F_52 ( V_2 , V_17 , V_36 ) ;
if ( ! F_28 ( V_2 , V_48 ) )
return NULL ;
V_27 = V_17 ;
V_76 = V_36 ;
while ( 1 ) {
if ( V_36 )
V_36 -= 1 ;
else {
V_17 = F_114 ( V_2 , V_17 ) ;
if ( ! V_17 )
break;
if ( F_26 ( V_17 ) )
return V_17 ;
V_36 = V_17 -> V_37 - 1 ;
}
if ( V_17 -> V_20 [ V_36 ] . V_3 == V_3 &&
V_17 -> V_20 [ V_36 ] . V_4 == V_4 )
return F_52 ( V_2 , V_17 , V_36 ) ;
if ( F_47 ( V_2 , & V_17 -> V_20 [ V_36 ] . V_48 , V_48 ) < 0 )
break;
}
V_17 = V_27 ;
V_36 = V_76 ;
while ( 1 ) {
if ( ++ V_36 >= V_17 -> V_37 ) {
V_17 = F_115 ( V_2 , V_17 ) ;
if ( ! V_17 )
break;
if ( F_26 ( V_17 ) )
return V_17 ;
V_36 = 0 ;
}
if ( V_17 -> V_20 [ V_36 ] . V_3 == V_3 &&
V_17 -> V_20 [ V_36 ] . V_4 == V_4 )
return F_52 ( V_2 , V_17 , V_36 ) ;
if ( F_47 ( V_2 , & V_17 -> V_20 [ V_36 ] . V_48 , V_48 ) > 0 )
break;
}
return NULL ;
}
int F_117 ( struct V_1 * V_2 , union V_64 * V_48 , int V_34 ,
int V_3 , int V_4 )
{
struct V_16 * V_17 ;
V_17 = F_116 ( V_2 , V_48 , V_34 , V_3 , V_4 ) ;
if ( ! V_17 )
return 0 ;
if ( F_26 ( V_17 ) )
return F_55 ( V_17 ) ;
return F_63 ( V_17 ) ? 1 : 2 ;
}
static int F_118 ( struct V_1 * V_2 , union V_64 * V_48 ,
int V_3 , int V_4 )
{
struct V_18 * V_19 ;
struct V_16 * V_17 , * V_27 ;
int V_36 , V_96 , V_24 , V_76 ;
const int V_150 = ! F_28 ( V_2 , V_48 ) ;
V_96 = F_64 ( V_2 , V_48 , & V_17 , & V_36 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( ! V_96 )
return 0 ;
V_19 = & V_17 -> V_20 [ V_36 ] ;
if ( V_3 == V_19 -> V_3 && V_4 == V_19 -> V_4 )
return 1 ;
if ( V_150 )
return 0 ;
V_27 = V_17 ;
V_76 = V_36 ;
while ( 1 ) {
V_24 = F_56 ( V_2 , & V_17 , & V_36 ) ;
if ( V_24 == - V_78 )
break;
if ( V_24 )
return V_24 ;
if ( F_47 ( V_2 , V_48 , & V_17 -> V_20 [ V_36 ] . V_48 ) )
break;
V_19 = & V_17 -> V_20 [ V_36 ] ;
if ( V_3 == V_19 -> V_3 && V_4 == V_19 -> V_4 )
return 1 ;
}
V_17 = V_27 ;
V_36 = V_76 ;
while ( 1 ) {
V_24 = F_54 ( V_2 , & V_17 , & V_36 ) ;
if ( V_24 ) {
if ( V_24 == - V_78 )
return 0 ;
return V_24 ;
}
if ( F_47 ( V_2 , V_48 , & V_17 -> V_20 [ V_36 ] . V_48 ) )
break;
V_19 = & V_17 -> V_20 [ V_36 ] ;
if ( V_3 == V_19 -> V_3 && V_4 == V_19 -> V_4 )
return 1 ;
}
return 0 ;
}
int F_119 ( struct V_1 * V_2 , union V_64 * V_48 , int V_34 ,
int V_3 , int V_4 , int V_151 )
{
int V_24 ;
F_71 ( & V_2 -> V_100 ) ;
if ( V_151 ) {
V_24 = F_117 ( V_2 , V_48 , V_34 , V_3 , V_4 ) ;
if ( V_24 < 0 )
goto V_125;
if ( V_24 == 1 )
V_24 = 0 ;
else if ( V_24 == 2 )
V_24 = 1 ;
else
F_120 ( V_24 != 0 ) ;
} else
V_24 = F_118 ( V_2 , V_48 , V_3 , V_4 ) ;
V_125:
F_72 ( & V_2 -> V_100 ) ;
return V_24 ;
}
int F_121 ( struct V_1 * V_2 , union V_64 * V_48 , int V_34 ,
int V_3 , int V_4 )
{
struct V_16 * V_17 ;
int V_24 = 0 ;
F_71 ( & V_2 -> V_100 ) ;
V_17 = F_116 ( V_2 , V_48 , V_34 , V_3 , V_4 ) ;
if ( ! V_17 )
goto V_125;
if ( F_26 ( V_17 ) ) {
V_24 = F_55 ( V_17 ) ;
goto V_125;
}
V_17 = F_62 ( V_2 , V_17 ) ;
if ( F_26 ( V_17 ) ) {
V_24 = F_55 ( V_17 ) ;
goto V_125;
}
V_125:
F_72 ( & V_2 -> V_100 ) ;
return V_24 ;
}
int F_122 ( struct V_1 * V_2 , const struct V_152 * V_152 ,
T_3 V_153 )
{
int V_24 , V_36 ;
union V_64 V_137 , V_138 , * V_48 ;
struct V_16 * V_17 ;
unsigned int V_104 ;
if ( ! F_123 ( V_152 -> V_154 ) )
return 0 ;
if ( ! ( V_155 & V_156 ) )
return 0 ;
V_104 = ( V_153 + V_157 - 1 ) >> V_158 ;
F_124 ( V_2 , & V_137 , V_152 -> V_159 , V_104 ) ;
F_125 ( V_2 , & V_138 , V_152 -> V_159 ) ;
F_71 ( & V_2 -> V_100 ) ;
V_24 = F_64 ( V_2 , & V_137 , & V_17 , & V_36 ) ;
if ( V_24 < 0 )
goto V_125;
if ( V_24 ) {
V_24 = - V_79 ;
V_48 = & V_137 ;
goto V_160;
}
V_24 = F_54 ( V_2 , & V_17 , & V_36 ) ;
if ( V_24 == - V_78 ) {
V_24 = 0 ;
goto V_125;
}
if ( V_24 < 0 )
goto V_125;
F_17 ( V_24 == 0 ) ;
V_48 = & V_17 -> V_20 [ V_36 ] . V_48 ;
if ( ! F_101 ( V_2 , V_48 , & V_137 , & V_138 ) )
goto V_125;
V_160:
V_104 = F_75 ( V_2 , V_48 ) ;
F_5 ( L_41
L_42 , ( unsigned long ) V_152 -> V_159 , V_153 ,
( ( T_3 ) V_104 ) << V_158 , F_44 ( V_48 ) ) ;
F_126 ( V_2 , V_152 ) ;
F_30 () ;
V_24 = - V_79 ;
V_125:
F_72 ( & V_2 -> V_100 ) ;
return V_24 ;
}
