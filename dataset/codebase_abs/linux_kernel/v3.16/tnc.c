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
struct V_5 * V_6 , * V_25 ;
F_12 (old_idx, n, &c->old_idx, rb)
F_6 ( V_6 ) ;
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
const int V_25 = V_27 -> V_36 ;
for ( V_35 = 0 ; V_35 < V_25 ; V_35 ++ ) {
struct V_18 * V_19 = & V_27 -> V_20 [ V_35 ] ;
if ( V_19 -> V_17 )
V_19 -> V_17 -> V_10 = V_27 ;
}
}
F_19 ( & V_2 -> V_37 ) ;
return V_27 ;
}
static int F_20 ( struct V_1 * V_2 , int V_3 , int V_38 )
{
V_2 -> V_39 -= F_21 ( V_38 , 8 ) ;
return F_22 ( V_2 , V_3 , V_38 ) ;
}
static struct V_16 * F_23 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_16 * V_17 = V_19 -> V_17 ;
struct V_16 * V_27 ;
int V_24 ;
if ( ! F_24 ( V_17 ) ) {
if ( ! F_25 ( V_30 , & V_17 -> V_31 ) ) {
F_19 ( & V_2 -> V_37 ) ;
F_26 ( & V_2 -> V_40 ) ;
F_26 ( & V_41 ) ;
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
const void * V_42 )
{
int V_24 ;
void * V_43 ;
const struct V_44 * V_45 = V_42 ;
F_17 ( ! V_19 -> V_46 ) ;
F_17 ( V_19 -> V_22 != 0 ) ;
F_17 ( F_29 ( V_2 , & V_19 -> V_47 ) ) ;
V_24 = F_30 ( V_2 , V_45 ) ;
if ( V_24 ) {
F_31 () ;
F_32 ( V_2 , V_45 ) ;
return V_24 ;
}
V_43 = F_33 ( V_42 , V_19 -> V_22 , V_11 ) ;
if ( ! V_43 )
return 0 ;
V_19 -> V_46 = V_43 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_18 * V_19 ,
void * V_42 )
{
int V_24 ;
F_17 ( ! V_19 -> V_46 ) ;
F_17 ( V_19 -> V_22 != 0 ) ;
V_24 = F_30 ( V_2 , V_42 ) ;
if ( V_24 ) {
F_31 () ;
F_32 ( V_2 , V_42 ) ;
return V_24 ;
}
V_19 -> V_46 = V_42 ;
return 0 ;
}
static void F_35 ( struct V_18 * V_19 )
{
if ( ! V_19 -> V_46 )
return;
F_6 ( V_19 -> V_46 ) ;
V_19 -> V_46 = NULL ;
}
static int F_36 ( struct V_1 * V_2 , struct V_18 * V_19 ,
void * V_42 )
{
int V_24 ;
F_17 ( F_29 ( V_2 , & V_19 -> V_47 ) ) ;
if ( V_19 -> V_46 ) {
F_17 ( V_19 -> V_22 != 0 ) ;
memcpy ( V_42 , V_19 -> V_46 , V_19 -> V_22 ) ;
return 0 ;
}
V_24 = F_37 ( V_2 , V_19 , V_42 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_28 ( V_2 , V_19 , V_42 ) ;
return V_24 ;
}
static int F_38 ( const struct V_1 * V_2 , void * V_48 , int type ,
int V_22 , int V_3 , int V_4 )
{
int V_24 , V_49 ;
struct V_50 * V_51 = V_48 ;
T_1 V_52 , V_53 ;
F_39 ( L_2 , V_3 , V_4 , F_40 ( type ) , V_22 ) ;
V_24 = F_41 ( V_2 , V_3 , V_48 , V_4 , V_22 , 1 ) ;
if ( V_24 ) {
F_5 ( L_3 ,
type , V_3 , V_4 , V_24 ) ;
return V_24 ;
}
if ( F_42 ( V_51 -> V_54 ) != V_55 )
return 0 ;
if ( V_51 -> V_56 != type )
return 0 ;
V_49 = F_42 ( V_51 -> V_22 ) ;
if ( V_49 != V_22 )
return 0 ;
if ( type == V_57 && V_2 -> V_58 && ! V_2 -> V_59 &&
! V_2 -> V_60 )
return 1 ;
V_52 = F_43 ( V_61 , V_48 + 8 , V_49 - 8 ) ;
V_53 = F_42 ( V_51 -> V_52 ) ;
if ( V_52 != V_53 )
return 0 ;
return 1 ;
}
static int F_44 ( struct V_1 * V_2 , const union V_62 * V_47 ,
struct V_18 * V_19 , void * V_42 )
{
int V_63 ;
F_45 ( V_47 , L_4 , V_19 -> V_3 , V_19 -> V_4 ) ;
V_63 = F_38 ( V_2 , V_42 , F_46 ( V_2 , V_47 ) , V_19 -> V_22 , V_19 -> V_3 ,
V_19 -> V_4 ) ;
if ( V_63 == 1 ) {
union V_62 V_64 ;
struct V_44 * V_45 = V_42 ;
F_47 ( V_2 , & V_45 -> V_47 , & V_64 ) ;
if ( F_48 ( V_2 , V_47 , & V_64 ) != 0 )
V_63 = 0 ;
}
if ( V_63 == 0 && V_2 -> V_65 )
F_49 ( V_47 , L_5 ,
V_19 -> V_3 , V_19 -> V_4 , V_19 -> V_22 ) ;
return V_63 ;
}
static int F_50 ( struct V_1 * V_2 , struct V_18 * V_19 ,
const struct V_66 * V_67 )
{
struct V_44 * V_45 ;
int V_68 , V_24 ;
if ( ! V_19 -> V_46 ) {
V_45 = F_2 ( V_19 -> V_22 , V_11 ) ;
if ( ! V_45 )
return - V_12 ;
V_24 = F_37 ( V_2 , V_19 , V_45 ) ;
if ( V_24 )
goto V_69;
V_24 = F_34 ( V_2 , V_19 , V_45 ) ;
if ( V_24 )
goto V_69;
} else
V_45 = V_19 -> V_46 ;
V_68 = F_51 ( V_45 -> V_68 ) ;
V_24 = memcmp ( V_45 -> V_70 , V_67 -> V_70 , F_52 ( int , V_68 , V_67 -> V_22 ) ) ;
if ( V_24 == 0 ) {
if ( V_68 == V_67 -> V_22 )
return V_71 ;
else if ( V_68 < V_67 -> V_22 )
return V_72 ;
else
return V_73 ;
} else if ( V_24 < 0 )
return V_72 ;
else
return V_73 ;
V_69:
F_6 ( V_45 ) ;
return V_24 ;
}
static struct V_16 * F_53 ( struct V_1 * V_2 ,
struct V_16 * V_17 , int V_25 )
{
struct V_18 * V_19 ;
V_19 = & V_17 -> V_20 [ V_25 ] ;
if ( V_19 -> V_17 )
V_17 = V_19 -> V_17 ;
else
V_17 = F_54 ( V_2 , V_19 , V_17 , V_25 ) ;
return V_17 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_16 * * V_27 , int * V_25 )
{
struct V_16 * V_17 = * V_27 ;
int V_74 = * V_25 ;
V_74 += 1 ;
if ( V_74 < V_17 -> V_36 ) {
* V_25 = V_74 ;
return 0 ;
}
while ( 1 ) {
struct V_16 * V_75 ;
V_75 = V_17 -> V_10 ;
if ( ! V_75 )
return - V_76 ;
V_74 = V_17 -> V_21 + 1 ;
V_17 = V_75 ;
if ( V_74 < V_17 -> V_36 ) {
V_17 = F_53 ( V_2 , V_17 , V_74 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
while ( V_17 -> V_34 != 0 ) {
V_17 = F_53 ( V_2 , V_17 , 0 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
}
V_74 = 0 ;
break;
}
}
* V_27 = V_17 ;
* V_25 = V_74 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_16 * * V_27 , int * V_25 )
{
struct V_16 * V_17 = * V_27 ;
int V_74 = * V_25 ;
if ( V_74 > 0 ) {
* V_25 = V_74 - 1 ;
return 0 ;
}
while ( 1 ) {
struct V_16 * V_75 ;
V_75 = V_17 -> V_10 ;
if ( ! V_75 )
return - V_76 ;
V_74 = V_17 -> V_21 - 1 ;
V_17 = V_75 ;
if ( V_74 >= 0 ) {
V_17 = F_53 ( V_2 , V_17 , V_74 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
while ( V_17 -> V_34 != 0 ) {
V_74 = V_17 -> V_36 - 1 ;
V_17 = F_53 ( V_2 , V_17 , V_74 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
}
V_74 = V_17 -> V_36 - 1 ;
break;
}
}
* V_27 = V_17 ;
* V_25 = V_74 ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , const union V_62 * V_47 ,
struct V_16 * * V_27 , int * V_25 ,
const struct V_66 * V_67 )
{
int V_24 ;
V_24 = F_50 ( V_2 , & ( * V_27 ) -> V_20 [ * V_25 ] , V_67 ) ;
if ( F_3 ( V_24 < 0 ) )
return V_24 ;
if ( V_24 == V_71 )
return 1 ;
if ( V_24 == V_73 ) {
while ( 1 ) {
V_24 = F_57 ( V_2 , V_27 , V_25 ) ;
if ( V_24 == - V_76 ) {
F_17 ( * V_25 == 0 ) ;
* V_25 = - 1 ;
return 0 ;
}
if ( V_24 < 0 )
return V_24 ;
if ( F_48 ( V_2 , & ( * V_27 ) -> V_20 [ * V_25 ] . V_47 , V_47 ) ) {
if ( * V_25 == ( * V_27 ) -> V_36 - 1 ) {
V_24 = F_55 ( V_2 , V_27 , V_25 ) ;
if ( V_24 ) {
F_17 ( 0 ) ;
if ( V_24 == - V_76 )
V_24 = - V_77 ;
return V_24 ;
}
F_17 ( * V_25 == 0 ) ;
* V_25 = - 1 ;
}
return 0 ;
}
V_24 = F_50 ( V_2 , & ( * V_27 ) -> V_20 [ * V_25 ] , V_67 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_24 == V_72 )
return 0 ;
if ( V_24 == V_71 )
return 1 ;
F_17 ( V_24 == V_73 ) ;
}
} else {
int V_74 = * V_25 ;
struct V_16 * V_17 = * V_27 ;
while ( 1 ) {
V_24 = F_55 ( V_2 , & V_17 , & V_74 ) ;
if ( V_24 == - V_76 )
return 0 ;
if ( V_24 < 0 )
return V_24 ;
if ( F_48 ( V_2 , & V_17 -> V_20 [ V_74 ] . V_47 , V_47 ) )
return 0 ;
V_24 = F_50 ( V_2 , & V_17 -> V_20 [ V_74 ] , V_67 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_24 == V_73 )
return 0 ;
* V_27 = V_17 ;
* V_25 = V_74 ;
if ( V_24 == V_71 )
return 1 ;
F_17 ( V_24 == V_72 ) ;
}
}
}
static int F_59 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
const struct V_66 * V_67 )
{
struct V_44 * V_45 ;
int V_68 , V_24 ;
if ( ! V_19 -> V_46 ) {
V_45 = F_2 ( V_19 -> V_22 , V_11 ) ;
if ( ! V_45 )
return - V_12 ;
V_24 = F_44 ( V_2 , & V_19 -> V_47 , V_19 , V_45 ) ;
if ( V_24 < 0 )
goto V_69;
if ( V_24 == 0 ) {
V_24 = V_78 ;
goto V_69;
}
F_17 ( V_24 == 1 ) ;
V_24 = F_34 ( V_2 , V_19 , V_45 ) ;
if ( V_24 )
goto V_69;
} else
V_45 = V_19 -> V_46 ;
V_68 = F_51 ( V_45 -> V_68 ) ;
V_24 = memcmp ( V_45 -> V_70 , V_67 -> V_70 , F_52 ( int , V_68 , V_67 -> V_22 ) ) ;
if ( V_24 == 0 ) {
if ( V_68 == V_67 -> V_22 )
return V_71 ;
else if ( V_68 < V_67 -> V_22 )
return V_72 ;
else
return V_73 ;
} else if ( V_24 < 0 )
return V_72 ;
else
return V_73 ;
V_69:
F_6 ( V_45 ) ;
return V_24 ;
}
static int F_60 ( struct V_1 * V_2 ,
const union V_62 * V_47 ,
struct V_16 * * V_27 , int * V_25 ,
const struct V_66 * V_67 , int V_79 )
{
struct V_16 * V_80 = NULL , * V_17 = * V_27 ;
int V_81 ( V_82 ) , V_24 , V_83 , V_84 = 0 , V_74 = * V_25 ;
V_83 = F_59 ( V_2 , & V_17 -> V_20 [ V_74 ] , V_67 ) ;
if ( F_3 ( V_83 < 0 ) )
return V_83 ;
if ( V_83 == V_71 )
return 1 ;
if ( V_83 == V_78 ) {
V_80 = V_17 ;
V_82 = V_74 ;
V_84 = 1 ;
} else if ( ! V_79 )
V_84 = 1 ;
if ( V_83 == V_73 || V_84 ) {
while ( 1 ) {
V_24 = F_57 ( V_2 , V_27 , V_25 ) ;
if ( V_24 == - V_76 ) {
F_17 ( * V_25 == 0 ) ;
* V_25 = - 1 ;
break;
}
if ( V_24 < 0 )
return V_24 ;
if ( F_48 ( V_2 , & ( * V_27 ) -> V_20 [ * V_25 ] . V_47 , V_47 ) ) {
if ( * V_25 == ( * V_27 ) -> V_36 - 1 ) {
V_24 = F_55 ( V_2 , V_27 , V_25 ) ;
if ( V_24 ) {
F_17 ( 0 ) ;
if ( V_24 == - V_76 )
V_24 = - V_77 ;
return V_24 ;
}
F_17 ( * V_25 == 0 ) ;
* V_25 = - 1 ;
}
break;
}
V_24 = F_59 ( V_2 , & ( * V_27 ) -> V_20 [ * V_25 ] , V_67 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_24 == V_71 )
return 1 ;
if ( V_24 == V_78 ) {
V_80 = * V_27 ;
V_82 = * V_25 ;
continue;
}
if ( ! V_79 )
continue;
if ( V_24 == V_72 )
break;
else
V_84 = 0 ;
}
}
if ( V_83 == V_72 || V_84 ) {
* V_27 = V_17 ;
* V_25 = V_74 ;
while ( 1 ) {
V_24 = F_55 ( V_2 , & V_17 , & V_74 ) ;
if ( V_24 == - V_76 )
break;
if ( V_24 < 0 )
return V_24 ;
if ( F_48 ( V_2 , & V_17 -> V_20 [ V_74 ] . V_47 , V_47 ) )
break;
V_24 = F_59 ( V_2 , & V_17 -> V_20 [ V_74 ] , V_67 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_24 == V_73 )
break;
* V_27 = V_17 ;
* V_25 = V_74 ;
if ( V_24 == V_71 )
return 1 ;
if ( V_24 == V_78 ) {
V_80 = V_17 ;
V_82 = V_74 ;
}
}
}
if ( V_79 || ! V_80 )
return 0 ;
F_49 ( V_47 , L_6 ,
V_80 -> V_20 [ V_82 ] . V_3 , V_80 -> V_20 [ V_82 ] . V_4 ,
V_80 -> V_20 [ V_82 ] . V_22 ) ;
* V_27 = V_80 ;
* V_25 = V_82 ;
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
const union V_62 * V_47 ,
struct V_16 * * V_27 , int * V_25 ,
int V_3 , int V_4 )
{
struct V_16 * V_17 ;
int V_74 , V_24 ;
V_17 = * V_27 ;
V_74 = * V_25 ;
if ( F_61 ( & V_17 -> V_20 [ V_74 ] , V_3 , V_4 ) )
return 1 ;
while ( 1 ) {
V_24 = F_57 ( V_2 , & V_17 , & V_74 ) ;
if ( V_24 == - V_76 )
break;
if ( V_24 < 0 )
return V_24 ;
if ( F_48 ( V_2 , & V_17 -> V_20 [ V_74 ] . V_47 , V_47 ) )
break;
if ( F_61 ( & V_17 -> V_20 [ V_74 ] , V_3 , V_4 ) ) {
* V_27 = V_17 ;
* V_25 = V_74 ;
return 1 ;
}
}
V_17 = * V_27 ;
V_74 = * V_25 ;
while ( 1 ) {
V_24 = F_55 ( V_2 , & V_17 , & V_74 ) ;
if ( V_24 == - V_76 )
return 0 ;
if ( V_24 < 0 )
return V_24 ;
if ( F_48 ( V_2 , & V_17 -> V_20 [ V_74 ] . V_47 , V_47 ) )
return 0 ;
* V_27 = V_17 ;
* V_25 = V_74 ;
if ( F_61 ( & V_17 -> V_20 [ V_74 ] , V_3 , V_4 ) )
return 1 ;
}
}
static struct V_16 * F_63 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_16 * V_75 ;
int * V_85 = V_2 -> V_86 , V_9 = 0 ;
F_17 ( V_2 -> V_23 . V_17 ) ;
F_17 ( V_17 ) ;
if ( V_2 -> V_23 . V_17 -> V_34 > V_87 ) {
F_6 ( V_2 -> V_86 ) ;
V_2 -> V_86 = F_2 ( V_2 -> V_23 . V_17 -> V_34 * sizeof( int ) ,
V_11 ) ;
if ( ! V_2 -> V_86 )
return F_14 ( - V_12 ) ;
V_85 = V_2 -> V_86 ;
}
if ( V_2 -> V_23 . V_17 -> V_34 ) {
while ( 1 ) {
int V_25 ;
V_75 = V_17 -> V_10 ;
if ( ! V_75 )
break;
V_25 = V_17 -> V_21 ;
F_17 ( V_9 < V_2 -> V_23 . V_17 -> V_34 ) ;
V_85 [ V_9 ++ ] = V_25 ;
if ( ! V_75 -> V_29 && F_64 ( V_17 ) )
break;
V_17 = V_75 ;
}
}
while ( 1 ) {
struct V_18 * V_19 ;
V_75 = V_17 -> V_10 ;
if ( V_75 ) {
F_17 ( V_85 [ V_9 - 1 ] >= 0 ) ;
F_17 ( V_85 [ V_9 - 1 ] < V_75 -> V_36 ) ;
V_19 = & V_75 -> V_20 [ V_85 [ -- V_9 ] ] ;
V_17 = F_23 ( V_2 , V_19 ) ;
} else {
F_17 ( V_17 == V_2 -> V_23 . V_17 ) ;
V_17 = F_23 ( V_2 , & V_2 -> V_23 ) ;
}
if ( F_27 ( V_17 ) || ! V_9 )
break;
F_17 ( V_85 [ V_9 - 1 ] >= 0 ) ;
F_17 ( V_85 [ V_9 - 1 ] < V_17 -> V_36 ) ;
V_17 = V_17 -> V_20 [ V_85 [ V_9 - 1 ] ] . V_17 ;
}
return V_17 ;
}
int F_65 ( struct V_1 * V_2 , const union V_62 * V_47 ,
struct V_16 * * V_27 , int * V_25 )
{
int V_24 , V_88 ;
struct V_16 * V_17 ;
unsigned long time = F_66 () ;
F_45 ( V_47 , L_7 ) ;
F_17 ( F_46 ( V_2 , V_47 ) < V_89 ) ;
V_17 = V_2 -> V_23 . V_17 ;
if ( F_3 ( ! V_17 ) ) {
V_17 = F_54 ( V_2 , & V_2 -> V_23 , NULL , 0 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
}
V_17 -> time = time ;
while ( 1 ) {
struct V_18 * V_19 ;
V_88 = F_67 ( V_2 , V_17 , V_47 , V_25 ) ;
if ( V_17 -> V_34 == 0 )
break;
if ( * V_25 < 0 )
* V_25 = 0 ;
V_19 = & V_17 -> V_20 [ * V_25 ] ;
if ( V_19 -> V_17 ) {
V_17 -> time = time ;
V_17 = V_19 -> V_17 ;
continue;
}
V_17 = F_54 ( V_2 , V_19 , V_17 , * V_25 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
}
* V_27 = V_17 ;
if ( V_88 || ! F_29 ( V_2 , V_47 ) || * V_25 != - 1 ) {
F_68 ( L_8 , V_88 , V_17 -> V_34 , * V_25 ) ;
return V_88 ;
}
V_24 = F_57 ( V_2 , & V_17 , V_25 ) ;
if ( V_24 == - V_76 ) {
F_68 ( L_9 , V_17 -> V_34 ) ;
* V_25 = - 1 ;
return 0 ;
}
if ( F_3 ( V_24 < 0 ) )
return V_24 ;
if ( F_48 ( V_2 , V_47 , & V_17 -> V_20 [ * V_25 ] . V_47 ) ) {
F_68 ( L_9 , V_17 -> V_34 ) ;
* V_25 = - 1 ;
return 0 ;
}
F_68 ( L_10 , V_17 -> V_34 , * V_25 ) ;
* V_27 = V_17 ;
return 1 ;
}
static int F_69 ( struct V_1 * V_2 , const union V_62 * V_47 ,
struct V_16 * * V_27 , int * V_25 )
{
int V_24 , V_88 ;
struct V_16 * V_17 ;
unsigned long time = F_66 () ;
F_45 ( V_47 , L_11 ) ;
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
V_88 = F_67 ( V_2 , V_17 , V_47 , V_25 ) ;
if ( V_17 -> V_34 == 0 )
break;
if ( * V_25 < 0 )
* V_25 = 0 ;
V_19 = & V_17 -> V_20 [ * V_25 ] ;
if ( V_19 -> V_17 ) {
V_17 -> time = time ;
V_17 = F_23 ( V_2 , V_19 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
continue;
}
V_17 = F_54 ( V_2 , V_19 , V_17 , * V_25 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
V_17 = F_23 ( V_2 , V_19 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
}
* V_27 = V_17 ;
if ( V_88 || ! F_29 ( V_2 , V_47 ) || * V_25 != - 1 ) {
F_68 ( L_8 , V_88 , V_17 -> V_34 , * V_25 ) ;
return V_88 ;
}
V_24 = F_57 ( V_2 , & V_17 , V_25 ) ;
if ( V_24 == - V_76 ) {
* V_25 = - 1 ;
F_68 ( L_9 , V_17 -> V_34 ) ;
return 0 ;
}
if ( F_3 ( V_24 < 0 ) )
return V_24 ;
if ( F_48 ( V_2 , V_47 , & V_17 -> V_20 [ * V_25 ] . V_47 ) ) {
* V_25 = - 1 ;
F_68 ( L_9 , V_17 -> V_34 ) ;
return 0 ;
}
if ( V_17 -> V_29 || ! F_64 ( V_17 ) ) {
V_17 = F_63 ( V_2 , V_17 ) ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
}
F_68 ( L_10 , V_17 -> V_34 , * V_25 ) ;
* V_27 = V_17 ;
return 1 ;
}
static int F_70 ( struct V_1 * V_2 , int V_3 , int V_90 )
{
int V_91 , V_92 ;
V_92 = V_2 -> V_92 ;
F_71 () ;
V_91 = V_2 -> V_93 ;
if ( V_90 == V_91 )
return 0 ;
if ( V_90 + 1 != V_91 )
return 1 ;
F_71 () ;
if ( V_92 != V_2 -> V_92 )
return 1 ;
if ( V_92 == V_3 )
return 1 ;
return 0 ;
}
int F_72 ( struct V_1 * V_2 , const union V_62 * V_47 ,
void * V_42 , int * V_3 , int * V_4 )
{
int V_94 , V_25 , V_24 , V_95 = 0 , V_90 ;
struct V_16 * V_17 ;
struct V_18 V_19 , * V_96 ;
V_97:
F_73 ( & V_2 -> V_98 ) ;
V_94 = F_65 ( V_2 , V_47 , & V_17 , & V_25 ) ;
if ( ! V_94 ) {
V_24 = - V_76 ;
goto V_99;
} else if ( V_94 < 0 ) {
V_24 = V_94 ;
goto V_99;
}
V_96 = & V_17 -> V_20 [ V_25 ] ;
if ( V_3 ) {
* V_3 = V_96 -> V_3 ;
* V_4 = V_96 -> V_4 ;
}
if ( F_29 ( V_2 , V_47 ) ) {
V_24 = F_36 ( V_2 , V_96 , V_42 ) ;
goto V_99;
}
if ( V_95 ) {
V_24 = F_37 ( V_2 , V_96 , V_42 ) ;
goto V_99;
}
V_19 = V_17 -> V_20 [ V_25 ] ;
V_90 = V_2 -> V_93 ;
F_74 ( & V_2 -> V_98 ) ;
if ( F_75 ( V_2 , V_19 . V_3 ) ) {
V_24 = F_37 ( V_2 , & V_19 , V_42 ) ;
return V_24 ;
}
V_24 = F_44 ( V_2 , V_47 , & V_19 , V_42 ) ;
if ( V_24 <= 0 || F_70 ( V_2 , V_19 . V_3 , V_90 ) ) {
V_95 = 1 ;
goto V_97;
}
return 0 ;
V_99:
F_74 ( & V_2 -> V_98 ) ;
return V_24 ;
}
int F_76 ( struct V_1 * V_2 , struct V_100 * V_101 )
{
int V_25 , V_24 = 0 , V_3 = - 1 , V_81 ( V_4 ) ;
int V_81 ( V_22 ) ;
unsigned int V_102 = F_77 ( V_2 , & V_101 -> V_47 ) ;
struct V_16 * V_17 ;
V_101 -> V_103 = 0 ;
V_101 -> V_104 = 0 ;
V_101 -> V_105 = 0 ;
F_73 ( & V_2 -> V_98 ) ;
V_24 = F_65 ( V_2 , & V_101 -> V_47 , & V_17 , & V_25 ) ;
if ( V_24 < 0 )
goto V_99;
if ( V_24 ) {
V_22 = V_17 -> V_20 [ V_25 ] . V_22 ;
if ( V_22 > V_101 -> V_106 ) {
V_24 = - V_77 ;
goto V_99;
}
V_101 -> V_20 [ V_101 -> V_103 ++ ] = V_17 -> V_20 [ V_25 ] ;
V_101 -> V_104 += 1 ;
V_3 = V_17 -> V_20 [ V_25 ] . V_3 ;
V_4 = F_21 ( V_17 -> V_20 [ V_25 ] . V_4 + V_22 , 8 ) ;
}
while ( 1 ) {
struct V_18 * V_19 ;
union V_62 * V_47 ;
unsigned int V_107 ;
V_24 = F_55 ( V_2 , & V_17 , & V_25 ) ;
if ( V_24 )
goto V_99;
V_19 = & V_17 -> V_20 [ V_25 ] ;
V_47 = & V_19 -> V_47 ;
if ( F_78 ( V_2 , V_47 ) != F_78 ( V_2 , & V_101 -> V_47 ) ||
F_46 ( V_2 , V_47 ) != V_108 ) {
V_24 = - V_76 ;
goto V_99;
}
if ( V_3 < 0 ) {
V_3 = V_19 -> V_3 ;
V_4 = F_21 ( V_19 -> V_4 + V_19 -> V_22 , 8 ) ;
V_22 = V_19 -> V_22 ;
if ( V_22 > V_101 -> V_106 ) {
V_24 = - V_77 ;
goto V_99;
}
} else {
if ( V_19 -> V_3 != V_3 || V_19 -> V_4 != V_4 )
goto V_99;
V_4 += F_21 ( V_19 -> V_22 , 8 ) ;
V_22 = F_21 ( V_22 , 8 ) + V_19 -> V_22 ;
if ( V_22 > V_101 -> V_106 )
goto V_99;
}
V_107 = F_77 ( V_2 , V_47 ) ;
V_101 -> V_104 += ( V_107 - V_102 - 1 ) ;
if ( V_101 -> V_104 >= V_109 )
goto V_99;
V_102 = V_107 ;
V_101 -> V_20 [ V_101 -> V_103 ++ ] = * V_19 ;
V_101 -> V_104 += 1 ;
if ( V_101 -> V_103 >= V_109 )
goto V_99;
if ( V_101 -> V_104 >= V_109 )
goto V_99;
}
V_99:
if ( V_24 == - V_76 ) {
V_101 -> V_105 = 1 ;
V_24 = 0 ;
}
V_101 -> V_93 = V_2 -> V_93 ;
F_74 ( & V_2 -> V_98 ) ;
if ( V_24 )
return V_24 ;
if ( V_101 -> V_104 > V_109 )
V_101 -> V_104 = V_109 ;
if ( V_110 == 1 ||
! ( V_101 -> V_104 & ( V_110 - 1 ) ) )
return 0 ;
if ( V_101 -> V_105 ) {
V_101 -> V_104 += V_110 - 1 ;
return 0 ;
}
V_102 = F_77 ( V_2 , & V_101 -> V_47 ) + V_101 -> V_104 ;
V_102 &= ~ ( V_110 - 1 ) ;
while ( V_101 -> V_103 ) {
if ( F_77 ( V_2 , & V_101 -> V_20 [ V_101 -> V_103 - 1 ] . V_47 ) < V_102 )
break;
V_101 -> V_103 -= 1 ;
}
return 0 ;
}
static int F_79 ( struct V_111 * V_112 , void * V_48 , int V_22 , int V_3 ,
int V_4 )
{
const struct V_1 * V_2 = V_112 -> V_2 ;
int V_113 , V_114 ;
F_39 ( L_12 , V_3 , V_4 , V_22 ) ;
F_17 ( V_112 && V_3 >= 0 && V_3 < V_2 -> V_115 && V_4 >= 0 ) ;
F_17 ( ! ( V_4 & 7 ) && V_4 < V_2 -> V_116 ) ;
F_17 ( V_4 + V_22 <= V_2 -> V_116 ) ;
F_80 ( & V_112 -> V_117 ) ;
V_114 = ( V_3 == V_112 -> V_3 && V_4 + V_22 > V_112 -> V_4 ) ;
if ( ! V_114 ) {
F_81 ( & V_112 -> V_117 ) ;
return F_41 ( V_2 , V_3 , V_48 , V_4 , V_22 , 0 ) ;
}
V_113 = V_112 -> V_4 - V_4 ;
if ( V_113 < 0 )
V_113 = 0 ;
memcpy ( V_48 + V_113 , V_112 -> V_48 + V_4 + V_113 - V_112 -> V_4 , V_22 - V_113 ) ;
F_81 ( & V_112 -> V_117 ) ;
if ( V_113 > 0 )
return F_41 ( V_2 , V_3 , V_48 , V_4 , V_113 , 0 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , void * V_48 ,
struct V_18 * V_19 )
{
union V_62 V_118 ;
struct V_50 * V_51 = V_48 ;
int V_24 , V_22 ;
if ( V_51 -> V_56 != V_57 ) {
F_5 ( L_13 ,
V_51 -> V_56 , V_57 ) ;
goto V_119;
}
V_24 = F_83 ( V_2 , V_48 , V_19 -> V_3 , V_19 -> V_4 , 0 , 0 ) ;
if ( V_24 ) {
F_5 ( L_14 , V_57 ) ;
goto V_99;
}
V_22 = F_42 ( V_51 -> V_22 ) ;
if ( V_22 != V_19 -> V_22 ) {
F_5 ( L_15 , V_22 , V_19 -> V_22 ) ;
goto V_119;
}
F_47 ( V_2 , V_48 + V_120 , & V_118 ) ;
if ( ! F_84 ( V_2 , & V_19 -> V_47 , & V_118 ) ) {
F_5 ( L_16 ,
V_19 -> V_3 , V_19 -> V_4 ) ;
F_45 ( & V_19 -> V_47 , L_17 ) ;
F_45 ( & V_118 , L_18 ) ;
goto V_119;
}
return 0 ;
V_119:
V_24 = - V_77 ;
V_99:
F_5 ( L_19 , V_19 -> V_3 , V_19 -> V_4 ) ;
F_32 ( V_2 , V_48 ) ;
F_31 () ;
return V_24 ;
}
int F_85 ( struct V_1 * V_2 , struct V_100 * V_101 )
{
int V_3 = V_101 -> V_20 [ 0 ] . V_3 , V_4 = V_101 -> V_20 [ 0 ] . V_4 , V_22 , V_24 , V_35 ;
struct V_111 * V_112 ;
void * V_48 ;
V_22 = V_101 -> V_20 [ V_101 -> V_103 - 1 ] . V_4 ;
V_22 += V_101 -> V_20 [ V_101 -> V_103 - 1 ] . V_22 - V_4 ;
if ( V_22 > V_101 -> V_106 ) {
F_5 ( L_20 , V_101 -> V_106 , V_22 ) ;
return - V_77 ;
}
V_112 = F_75 ( V_2 , V_3 ) ;
if ( V_112 )
V_24 = F_79 ( V_112 , V_101 -> V_48 , V_22 , V_3 , V_4 ) ;
else
V_24 = F_41 ( V_2 , V_3 , V_101 -> V_48 , V_4 , V_22 , 0 ) ;
if ( F_70 ( V_2 , V_3 , V_101 -> V_93 ) )
return - V_121 ;
if ( V_24 && V_24 != - V_122 ) {
F_5 ( L_21 ,
V_3 , V_4 , V_24 ) ;
F_31 () ;
F_45 ( & V_101 -> V_47 , L_22 ) ;
return V_24 ;
}
V_48 = V_101 -> V_48 ;
for ( V_35 = 0 ; V_35 < V_101 -> V_103 ; V_35 ++ ) {
V_24 = F_82 ( V_2 , V_48 , & V_101 -> V_20 [ V_35 ] ) ;
if ( V_24 )
return V_24 ;
V_48 = V_48 + F_21 ( V_101 -> V_20 [ V_35 ] . V_22 , 8 ) ;
}
return 0 ;
}
static int F_86 ( struct V_1 * V_2 , const union V_62 * V_47 ,
void * V_42 , const struct V_66 * V_67 )
{
int V_94 , V_25 , V_24 ;
struct V_16 * V_17 ;
F_45 ( V_47 , L_23 , V_67 -> V_22 , V_67 -> V_70 ) ;
F_73 ( & V_2 -> V_98 ) ;
V_94 = F_65 ( V_2 , V_47 , & V_17 , & V_25 ) ;
if ( ! V_94 ) {
V_24 = - V_76 ;
goto V_123;
} else if ( V_94 < 0 ) {
V_24 = V_94 ;
goto V_123;
}
F_17 ( V_25 >= 0 ) ;
V_24 = F_58 ( V_2 , V_47 , & V_17 , & V_25 , V_67 ) ;
F_68 ( L_24 , V_24 , V_17 , V_25 ) ;
if ( F_3 ( V_24 < 0 ) )
goto V_123;
if ( V_24 == 0 ) {
V_24 = - V_76 ;
goto V_123;
}
V_24 = F_36 ( V_2 , & V_17 -> V_20 [ V_25 ] , V_42 ) ;
V_123:
F_74 ( & V_2 -> V_98 ) ;
return V_24 ;
}
int F_87 ( struct V_1 * V_2 , const union V_62 * V_47 ,
void * V_42 , const struct V_66 * V_67 )
{
int V_24 , V_22 ;
const struct V_44 * V_45 = V_42 ;
V_24 = F_88 ( V_2 , V_47 , V_42 ) ;
if ( V_24 )
return V_24 ;
V_22 = F_51 ( V_45 -> V_68 ) ;
if ( V_67 -> V_22 == V_22 && ! memcmp ( V_45 -> V_70 , V_67 -> V_70 , V_22 ) )
return 0 ;
return F_86 ( V_2 , V_47 , V_42 , V_67 ) ;
}
static void F_89 ( const struct V_1 * V_2 ,
struct V_16 * V_17 )
{
union V_62 * V_47 , * V_118 ;
F_17 ( V_17 -> V_10 ) ;
F_17 ( V_17 -> V_21 == 0 ) ;
V_47 = & V_17 -> V_20 [ 0 ] . V_47 ;
V_118 = & V_17 -> V_10 -> V_20 [ 0 ] . V_47 ;
while ( F_48 ( V_2 , V_47 , V_118 ) < 0 ) {
F_90 ( V_2 , V_47 , V_118 ) ;
V_17 = V_17 -> V_10 ;
V_17 -> V_124 = 1 ;
if ( ! V_17 -> V_10 || V_17 -> V_21 )
break;
V_118 = & V_17 -> V_10 -> V_20 [ 0 ] . V_47 ;
}
}
static void F_91 ( struct V_16 * V_17 ,
const struct V_18 * V_19 , int V_25 )
{
int V_35 ;
F_17 ( F_64 ( V_17 ) ) ;
if ( V_17 -> V_34 ) {
for ( V_35 = V_17 -> V_36 ; V_35 > V_25 ; V_35 -- ) {
V_17 -> V_20 [ V_35 ] = V_17 -> V_20 [ V_35 - 1 ] ;
if ( V_17 -> V_20 [ V_35 ] . V_17 )
V_17 -> V_20 [ V_35 ] . V_17 -> V_21 = V_35 ;
}
if ( V_19 -> V_17 )
V_19 -> V_17 -> V_21 = V_25 ;
} else
for ( V_35 = V_17 -> V_36 ; V_35 > V_25 ; V_35 -- )
V_17 -> V_20 [ V_35 ] = V_17 -> V_20 [ V_35 - 1 ] ;
V_17 -> V_20 [ V_25 ] = * V_19 ;
V_17 -> V_36 += 1 ;
if ( V_25 == 0 )
V_17 -> V_124 = 1 ;
}
static int F_92 ( struct V_1 * V_2 , struct V_16 * V_17 ,
struct V_18 * V_19 , int V_25 )
{
struct V_16 * V_27 , * V_125 , * V_75 ;
int V_35 , V_126 , V_127 , V_128 = 0 ;
union V_62 * V_47 = & V_19 -> V_47 , * V_118 ;
F_17 ( V_25 >= 0 && V_25 <= V_2 -> V_129 ) ;
V_97:
V_75 = V_17 -> V_10 ;
if ( V_17 -> V_36 < V_2 -> V_129 ) {
F_17 ( V_25 != V_2 -> V_129 ) ;
F_45 ( V_47 , L_25 , V_25 , V_17 -> V_34 ) ;
F_91 ( V_17 , V_19 , V_25 ) ;
if ( V_25 == 0 && V_75 && V_17 -> V_21 == 0 )
F_89 ( V_2 , V_17 ) ;
return 0 ;
}
F_45 ( V_47 , L_26 , V_17 -> V_34 ) ;
if ( V_17 -> V_124 )
F_10 ( V_2 , V_17 ) ;
V_27 = F_93 ( V_2 -> V_28 , V_11 ) ;
if ( ! V_27 )
return - V_12 ;
V_27 -> V_10 = V_75 ;
V_27 -> V_34 = V_17 -> V_34 ;
if ( V_17 -> V_34 == 0 && F_46 ( V_2 , V_47 ) == V_108 ) {
if ( V_25 == V_2 -> V_129 ) {
V_118 = & V_17 -> V_20 [ V_25 - 1 ] . V_47 ;
if ( F_78 ( V_2 , V_118 ) == F_78 ( V_2 , V_47 ) &&
F_46 ( V_2 , V_118 ) == V_108 )
V_128 = 1 ;
} else
goto V_130;
} else if ( V_128 && V_25 != V_2 -> V_129 ) {
V_128 = 0 ;
V_130:
if ( V_25 >= ( V_2 -> V_129 + 1 ) / 2 ) {
V_118 = & V_17 -> V_20 [ 0 ] . V_47 ;
if ( F_78 ( V_2 , V_118 ) == F_78 ( V_2 , V_47 ) &&
F_46 ( V_2 , V_118 ) == V_108 ) {
V_118 = & V_17 -> V_20 [ V_25 ] . V_47 ;
if ( F_78 ( V_2 , V_118 ) != F_78 ( V_2 , V_47 ) ||
F_46 ( V_2 , V_118 ) != V_108 ) {
V_126 = V_25 ;
V_127 = V_2 -> V_129 - V_126 ;
V_125 = V_17 ;
goto V_131;
}
}
}
}
if ( V_128 ) {
V_126 = V_2 -> V_129 ;
V_127 = 0 ;
} else {
V_126 = ( V_2 -> V_129 + 1 ) / 2 ;
V_127 = V_2 -> V_129 - V_126 ;
}
if ( V_25 < V_126 ) {
V_125 = V_17 ;
V_127 += 1 ;
V_126 -= 1 ;
} else {
V_125 = V_27 ;
V_25 -= V_126 ;
if ( V_27 -> V_34 != 0 )
V_19 -> V_17 -> V_10 = V_27 ;
}
V_131:
F_15 ( V_30 , & V_27 -> V_31 ) ;
F_19 ( & V_2 -> V_37 ) ;
V_27 -> V_36 = V_127 ;
V_17 -> V_36 = V_126 ;
F_68 ( L_27 , V_127 , V_126 ) ;
for ( V_35 = 0 ; V_35 < V_127 ; V_35 ++ ) {
V_27 -> V_20 [ V_35 ] = V_17 -> V_20 [ V_126 + V_35 ] ;
if ( V_27 -> V_34 != 0 )
if ( V_27 -> V_20 [ V_35 ] . V_17 ) {
V_27 -> V_20 [ V_35 ] . V_17 -> V_10 = V_27 ;
V_27 -> V_20 [ V_35 ] . V_17 -> V_21 = V_35 ;
}
}
F_45 ( V_47 , L_28 , V_25 , V_27 -> V_34 ) ;
F_91 ( V_125 , V_19 , V_25 ) ;
if ( V_75 ) {
if ( V_25 == 0 && V_125 == V_17 && V_17 -> V_21 == 0 )
F_89 ( V_2 , V_17 ) ;
V_25 = V_17 -> V_21 + 1 ;
V_19 -> V_47 = V_27 -> V_20 [ 0 ] . V_47 ;
V_19 -> V_17 = V_27 ;
V_19 -> V_3 = 0 ;
V_19 -> V_4 = 0 ;
V_19 -> V_22 = 0 ;
V_17 = V_75 ;
goto V_97;
}
F_68 ( L_29 , V_17 -> V_34 + 1 ) ;
V_125 = F_93 ( V_2 -> V_28 , V_11 ) ;
if ( ! V_125 )
return - V_12 ;
V_125 -> V_36 = 2 ;
V_125 -> V_34 = V_17 -> V_34 + 1 ;
F_15 ( V_30 , & V_125 -> V_31 ) ;
F_19 ( & V_2 -> V_37 ) ;
V_125 -> V_20 [ 0 ] . V_47 = V_17 -> V_20 [ 0 ] . V_47 ;
V_125 -> V_20 [ 0 ] . V_17 = V_17 ;
V_125 -> V_20 [ 0 ] . V_3 = V_2 -> V_23 . V_3 ;
V_125 -> V_20 [ 0 ] . V_4 = V_2 -> V_23 . V_4 ;
V_125 -> V_20 [ 0 ] . V_22 = V_2 -> V_23 . V_22 ;
V_125 -> V_20 [ 1 ] . V_47 = V_27 -> V_20 [ 0 ] . V_47 ;
V_125 -> V_20 [ 1 ] . V_17 = V_27 ;
V_2 -> V_23 . V_3 = 0 ;
V_2 -> V_23 . V_4 = 0 ;
V_2 -> V_23 . V_22 = 0 ;
V_2 -> V_23 . V_17 = V_125 ;
V_27 -> V_10 = V_125 ;
V_27 -> V_21 = 1 ;
V_17 -> V_10 = V_125 ;
V_17 -> V_21 = 0 ;
return 0 ;
}
int F_94 ( struct V_1 * V_2 , const union V_62 * V_47 , int V_3 ,
int V_4 , int V_22 )
{
int V_94 , V_25 , V_24 = 0 ;
struct V_16 * V_17 ;
F_73 ( & V_2 -> V_98 ) ;
F_45 ( V_47 , L_30 , V_3 , V_4 , V_22 ) ;
V_94 = F_69 ( V_2 , V_47 , & V_17 , & V_25 ) ;
if ( ! V_94 ) {
struct V_18 V_19 ;
V_19 . V_17 = NULL ;
V_19 . V_3 = V_3 ;
V_19 . V_4 = V_4 ;
V_19 . V_22 = V_22 ;
F_90 ( V_2 , V_47 , & V_19 . V_47 ) ;
V_24 = F_92 ( V_2 , V_17 , & V_19 , V_25 + 1 ) ;
} else if ( V_94 == 1 ) {
struct V_18 * V_19 = & V_17 -> V_20 [ V_25 ] ;
F_35 ( V_19 ) ;
V_24 = F_22 ( V_2 , V_19 -> V_3 , V_19 -> V_22 ) ;
V_19 -> V_3 = V_3 ;
V_19 -> V_4 = V_4 ;
V_19 -> V_22 = V_22 ;
} else
V_24 = V_94 ;
if ( ! V_24 )
V_24 = F_95 ( V_2 , 0 ) ;
F_74 ( & V_2 -> V_98 ) ;
return V_24 ;
}
int F_96 ( struct V_1 * V_2 , const union V_62 * V_47 ,
int V_132 , int V_133 , int V_3 , int V_4 , int V_22 )
{
int V_94 , V_25 , V_24 = 0 ;
struct V_16 * V_17 ;
F_73 ( & V_2 -> V_98 ) ;
F_45 ( V_47 , L_31 , V_132 ,
V_133 , V_3 , V_4 , V_22 ) ;
V_94 = F_69 ( V_2 , V_47 , & V_17 , & V_25 ) ;
if ( V_94 < 0 ) {
V_24 = V_94 ;
goto V_123;
}
if ( V_94 == 1 ) {
struct V_18 * V_19 = & V_17 -> V_20 [ V_25 ] ;
V_94 = 0 ;
if ( V_19 -> V_3 == V_132 && V_19 -> V_4 == V_133 ) {
F_35 ( V_19 ) ;
V_24 = F_22 ( V_2 , V_19 -> V_3 , V_19 -> V_22 ) ;
if ( V_24 )
goto V_123;
V_19 -> V_3 = V_3 ;
V_19 -> V_4 = V_4 ;
V_19 -> V_22 = V_22 ;
V_94 = 1 ;
} else if ( F_29 ( V_2 , V_47 ) ) {
V_94 = F_62 ( V_2 , V_47 , & V_17 , & V_25 ,
V_132 , V_133 ) ;
F_68 ( L_32 ,
V_94 , V_17 , V_25 , V_132 , V_133 ) ;
if ( V_94 < 0 ) {
V_24 = V_94 ;
goto V_123;
}
if ( V_94 ) {
if ( V_17 -> V_29 || ! F_64 ( V_17 ) ) {
V_17 = F_63 ( V_2 , V_17 ) ;
if ( F_27 ( V_17 ) ) {
V_24 = F_56 ( V_17 ) ;
goto V_123;
}
}
V_19 = & V_17 -> V_20 [ V_25 ] ;
F_35 ( V_19 ) ;
V_24 = F_22 ( V_2 , V_19 -> V_3 ,
V_19 -> V_22 ) ;
if ( V_24 )
goto V_123;
V_19 -> V_3 = V_3 ;
V_19 -> V_4 = V_4 ;
V_19 -> V_22 = V_22 ;
}
}
}
if ( ! V_94 )
V_24 = F_22 ( V_2 , V_3 , V_22 ) ;
if ( ! V_24 )
V_24 = F_95 ( V_2 , 0 ) ;
V_123:
F_74 ( & V_2 -> V_98 ) ;
return V_24 ;
}
int F_97 ( struct V_1 * V_2 , const union V_62 * V_47 ,
int V_3 , int V_4 , int V_22 , const struct V_66 * V_67 )
{
int V_94 , V_25 , V_24 = 0 ;
struct V_16 * V_17 ;
F_73 ( & V_2 -> V_98 ) ;
F_45 ( V_47 , L_33 ,
V_3 , V_4 , V_67 -> V_22 , V_67 -> V_70 ) ;
V_94 = F_69 ( V_2 , V_47 , & V_17 , & V_25 ) ;
if ( V_94 < 0 ) {
V_24 = V_94 ;
goto V_123;
}
if ( V_94 == 1 ) {
if ( V_2 -> V_65 )
V_94 = F_60 ( V_2 , V_47 , & V_17 , & V_25 ,
V_67 , 1 ) ;
else
V_94 = F_58 ( V_2 , V_47 , & V_17 , & V_25 , V_67 ) ;
F_68 ( L_24 , V_94 , V_17 , V_25 ) ;
if ( V_94 < 0 ) {
V_24 = V_94 ;
goto V_123;
}
if ( V_17 -> V_29 || ! F_64 ( V_17 ) ) {
V_17 = F_63 ( V_2 , V_17 ) ;
if ( F_27 ( V_17 ) ) {
V_24 = F_56 ( V_17 ) ;
goto V_123;
}
}
if ( V_94 == 1 ) {
struct V_18 * V_19 = & V_17 -> V_20 [ V_25 ] ;
F_35 ( V_19 ) ;
V_24 = F_22 ( V_2 , V_19 -> V_3 , V_19 -> V_22 ) ;
V_19 -> V_3 = V_3 ;
V_19 -> V_4 = V_4 ;
V_19 -> V_22 = V_22 ;
goto V_123;
}
}
if ( ! V_94 ) {
struct V_18 V_19 ;
V_19 . V_17 = NULL ;
V_19 . V_3 = V_3 ;
V_19 . V_4 = V_4 ;
V_19 . V_22 = V_22 ;
F_90 ( V_2 , V_47 , & V_19 . V_47 ) ;
V_24 = F_92 ( V_2 , V_17 , & V_19 , V_25 + 1 ) ;
if ( V_24 )
goto V_123;
if ( V_2 -> V_65 ) {
struct V_66 V_134 = { . V_70 = L_34 } ;
V_24 = F_95 ( V_2 , 0 ) ;
F_74 ( & V_2 -> V_98 ) ;
if ( V_24 )
return V_24 ;
return F_98 ( V_2 , V_47 , & V_134 ) ;
}
}
V_123:
if ( ! V_24 )
V_24 = F_95 ( V_2 , 0 ) ;
F_74 ( & V_2 -> V_98 ) ;
return V_24 ;
}
static int F_99 ( struct V_1 * V_2 , struct V_16 * V_17 , int V_25 )
{
struct V_18 * V_19 ;
struct V_16 * V_75 ;
int V_35 , V_24 ;
F_17 ( V_17 -> V_34 == 0 ) ;
F_17 ( V_25 >= 0 && V_25 < V_2 -> V_129 ) ;
F_45 ( & V_17 -> V_20 [ V_25 ] . V_47 , L_35 ) ;
V_19 = & V_17 -> V_20 [ V_25 ] ;
F_35 ( V_19 ) ;
V_24 = F_22 ( V_2 , V_19 -> V_3 , V_19 -> V_22 ) ;
if ( V_24 ) {
F_100 ( V_2 , V_17 ) ;
return V_24 ;
}
for ( V_35 = V_25 ; V_35 < V_17 -> V_36 - 1 ; V_35 ++ )
V_17 -> V_20 [ V_35 ] = V_17 -> V_20 [ V_35 + 1 ] ;
V_17 -> V_36 -= 1 ;
if ( V_17 -> V_36 > 0 )
return 0 ;
do {
F_17 ( ! F_18 ( V_17 ) ) ;
F_17 ( F_64 ( V_17 ) ) ;
V_75 = V_17 -> V_10 ;
V_25 = V_17 -> V_21 ;
F_26 ( & V_2 -> V_37 ) ;
V_24 = F_9 ( V_2 , V_17 ) ;
if ( V_24 )
return V_24 ;
if ( V_17 -> V_29 ) {
F_15 ( V_33 , & V_17 -> V_31 ) ;
F_19 ( & V_2 -> V_40 ) ;
F_19 ( & V_41 ) ;
} else
F_6 ( V_17 ) ;
V_17 = V_75 ;
} while ( V_17 -> V_36 == 1 );
V_17 -> V_36 -= 1 ;
F_17 ( V_17 -> V_34 != 0 ) ;
for ( V_35 = V_25 ; V_35 < V_17 -> V_36 ; V_35 ++ ) {
V_17 -> V_20 [ V_35 ] = V_17 -> V_20 [ V_35 + 1 ] ;
if ( V_17 -> V_20 [ V_35 ] . V_17 )
V_17 -> V_20 [ V_35 ] . V_17 -> V_21 = V_35 ;
}
if ( ! V_17 -> V_10 ) {
while ( V_17 -> V_36 == 1 && V_17 -> V_34 != 0 ) {
V_75 = V_17 ;
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
F_17 ( ! F_18 ( V_75 ) ) ;
F_17 ( F_64 ( V_75 ) ) ;
F_26 ( & V_2 -> V_37 ) ;
if ( V_75 -> V_29 ) {
F_15 ( V_33 , & V_75 -> V_31 ) ;
F_19 ( & V_2 -> V_40 ) ;
F_19 ( & V_41 ) ;
} else
F_6 ( V_75 ) ;
}
}
return 0 ;
}
int F_101 ( struct V_1 * V_2 , const union V_62 * V_47 )
{
int V_94 , V_25 , V_24 = 0 ;
struct V_16 * V_17 ;
F_73 ( & V_2 -> V_98 ) ;
F_45 ( V_47 , L_22 ) ;
V_94 = F_69 ( V_2 , V_47 , & V_17 , & V_25 ) ;
if ( V_94 < 0 ) {
V_24 = V_94 ;
goto V_123;
}
if ( V_94 == 1 )
V_24 = F_99 ( V_2 , V_17 , V_25 ) ;
if ( ! V_24 )
V_24 = F_95 ( V_2 , 0 ) ;
V_123:
F_74 ( & V_2 -> V_98 ) ;
return V_24 ;
}
int F_98 ( struct V_1 * V_2 , const union V_62 * V_47 ,
const struct V_66 * V_67 )
{
int V_25 , V_24 ;
struct V_16 * V_17 ;
F_73 ( & V_2 -> V_98 ) ;
F_45 ( V_47 , L_36 , V_67 -> V_22 , V_67 -> V_70 ) ;
V_24 = F_69 ( V_2 , V_47 , & V_17 , & V_25 ) ;
if ( V_24 < 0 )
goto V_123;
if ( V_24 ) {
if ( V_2 -> V_65 )
V_24 = F_60 ( V_2 , V_47 , & V_17 , & V_25 ,
V_67 , 0 ) ;
else
V_24 = F_58 ( V_2 , V_47 , & V_17 , & V_25 , V_67 ) ;
F_68 ( L_24 , V_24 , V_17 , V_25 ) ;
if ( V_24 < 0 )
goto V_123;
if ( V_24 ) {
if ( V_17 -> V_29 || ! F_64 ( V_17 ) ) {
V_17 = F_63 ( V_2 , V_17 ) ;
if ( F_27 ( V_17 ) ) {
V_24 = F_56 ( V_17 ) ;
goto V_123;
}
}
V_24 = F_99 ( V_2 , V_17 , V_25 ) ;
}
}
V_123:
if ( ! V_24 )
V_24 = F_95 ( V_2 , 0 ) ;
F_74 ( & V_2 -> V_98 ) ;
return V_24 ;
}
static int F_102 ( struct V_1 * V_2 , union V_62 * V_47 ,
union V_62 * V_135 , union V_62 * V_136 )
{
if ( F_48 ( V_2 , V_47 , V_135 ) < 0 )
return 0 ;
if ( F_48 ( V_2 , V_47 , V_136 ) > 0 )
return 0 ;
return 1 ;
}
int F_103 ( struct V_1 * V_2 , union V_62 * V_135 ,
union V_62 * V_136 )
{
int V_35 , V_25 , V_137 , V_24 = 0 ;
struct V_16 * V_17 ;
union V_62 * V_47 ;
F_73 ( & V_2 -> V_98 ) ;
while ( 1 ) {
V_24 = F_65 ( V_2 , V_135 , & V_17 , & V_25 ) ;
if ( V_24 < 0 )
goto V_123;
if ( V_24 )
V_47 = V_135 ;
else {
V_24 = F_55 ( V_2 , & V_17 , & V_25 ) ;
if ( V_24 == - V_76 ) {
V_24 = 0 ;
goto V_123;
}
if ( V_24 < 0 )
goto V_123;
V_47 = & V_17 -> V_20 [ V_25 ] . V_47 ;
if ( ! F_102 ( V_2 , V_47 , V_135 , V_136 ) ) {
V_24 = 0 ;
goto V_123;
}
}
if ( V_17 -> V_29 || ! F_64 ( V_17 ) ) {
V_17 = F_63 ( V_2 , V_17 ) ;
if ( F_27 ( V_17 ) ) {
V_24 = F_56 ( V_17 ) ;
goto V_123;
}
}
for ( V_35 = V_25 + 1 , V_137 = 0 ; V_35 < V_17 -> V_36 ; V_35 ++ , V_137 ++ ) {
V_47 = & V_17 -> V_20 [ V_35 ] . V_47 ;
if ( ! F_102 ( V_2 , V_47 , V_135 , V_136 ) )
break;
F_35 ( & V_17 -> V_20 [ V_35 ] ) ;
V_24 = F_22 ( V_2 , V_17 -> V_20 [ V_35 ] . V_3 ,
V_17 -> V_20 [ V_35 ] . V_22 ) ;
if ( V_24 ) {
F_100 ( V_2 , V_17 ) ;
goto V_123;
}
F_45 ( V_47 , L_37 ) ;
}
if ( V_137 ) {
for ( V_35 = V_25 + 1 + V_137 ; V_35 < V_17 -> V_36 ; V_35 ++ )
V_17 -> V_20 [ V_35 - V_137 ] = V_17 -> V_20 [ V_35 ] ;
V_17 -> V_36 -= V_137 ;
}
V_24 = F_99 ( V_2 , V_17 , V_25 ) ;
if ( V_24 )
goto V_123;
}
V_123:
if ( ! V_24 )
V_24 = F_95 ( V_2 , 0 ) ;
F_74 ( & V_2 -> V_98 ) ;
return V_24 ;
}
int F_104 ( struct V_1 * V_2 , T_2 V_138 )
{
union V_62 V_118 , V_139 ;
struct V_44 * V_140 , * V_141 = NULL ;
struct V_66 V_67 = { . V_70 = NULL } ;
F_68 ( L_38 , ( unsigned long ) V_138 ) ;
F_105 ( V_2 , & V_118 , V_138 ) ;
while ( 1 ) {
T_2 V_142 ;
int V_24 ;
V_140 = F_106 ( V_2 , & V_118 , & V_67 ) ;
if ( F_27 ( V_140 ) ) {
V_24 = F_56 ( V_140 ) ;
if ( V_24 == - V_76 )
break;
return V_24 ;
}
V_142 = F_107 ( V_140 -> V_138 ) ;
F_68 ( L_39 , V_140 -> V_70 ,
( unsigned long ) V_142 ) ;
V_67 . V_70 = V_140 -> V_70 ;
V_67 . V_22 = F_51 ( V_140 -> V_68 ) ;
V_24 = F_98 ( V_2 , & V_118 , & V_67 ) ;
if ( V_24 ) {
F_6 ( V_140 ) ;
return V_24 ;
}
F_108 ( V_2 , & V_118 , V_142 ) ;
F_109 ( V_2 , & V_139 , V_142 ) ;
V_24 = F_103 ( V_2 , & V_118 , & V_139 ) ;
if ( V_24 ) {
F_6 ( V_140 ) ;
return V_24 ;
}
F_6 ( V_141 ) ;
V_141 = V_140 ;
F_47 ( V_2 , & V_140 -> V_47 , & V_118 ) ;
}
F_6 ( V_141 ) ;
F_108 ( V_2 , & V_118 , V_138 ) ;
F_109 ( V_2 , & V_139 , V_138 ) ;
return F_103 ( V_2 , & V_118 , & V_139 ) ;
}
struct V_44 * F_106 ( struct V_1 * V_2 ,
union V_62 * V_47 ,
const struct V_66 * V_67 )
{
int V_25 , V_24 , type = F_46 ( V_2 , V_47 ) ;
struct V_16 * V_17 ;
struct V_44 * V_45 ;
struct V_18 * V_19 ;
union V_62 * V_143 ;
F_45 ( V_47 , L_40 , V_67 -> V_70 ? ( char * ) V_67 -> V_70 : L_41 ) ;
F_17 ( F_29 ( V_2 , V_47 ) ) ;
F_73 ( & V_2 -> V_98 ) ;
V_24 = F_65 ( V_2 , V_47 , & V_17 , & V_25 ) ;
if ( F_3 ( V_24 < 0 ) )
goto V_123;
if ( V_67 -> V_70 ) {
if ( V_24 ) {
V_24 = F_58 ( V_2 , V_47 , & V_17 , & V_25 , V_67 ) ;
F_68 ( L_24 ,
V_24 , V_17 , V_25 ) ;
if ( F_3 ( V_24 < 0 ) )
goto V_123;
}
V_24 = F_55 ( V_2 , & V_17 , & V_25 ) ;
if ( F_3 ( V_24 ) )
goto V_123;
} else {
if ( ! V_24 ) {
V_24 = F_55 ( V_2 , & V_17 , & V_25 ) ;
if ( V_24 )
goto V_123;
}
}
V_19 = & V_17 -> V_20 [ V_25 ] ;
V_45 = F_2 ( V_19 -> V_22 , V_11 ) ;
if ( F_3 ( ! V_45 ) ) {
V_24 = - V_12 ;
goto V_123;
}
V_143 = & V_19 -> V_47 ;
if ( F_78 ( V_2 , V_143 ) != F_78 ( V_2 , V_47 ) ||
F_46 ( V_2 , V_143 ) != type ) {
V_24 = - V_76 ;
goto V_69;
}
V_24 = F_36 ( V_2 , V_19 , V_45 ) ;
if ( F_3 ( V_24 ) )
goto V_69;
F_74 ( & V_2 -> V_98 ) ;
return V_45 ;
V_69:
F_6 ( V_45 ) ;
V_123:
F_74 ( & V_2 -> V_98 ) ;
return F_14 ( V_24 ) ;
}
static void F_110 ( struct V_1 * V_2 )
{
struct V_16 * V_29 ;
if ( ! V_2 -> V_29 )
return;
F_17 ( V_2 -> V_144 == V_145 ) ;
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
long V_25 , V_146 ;
V_25 = F_112 ( & V_2 -> V_40 ) ;
V_146 = F_113 ( V_2 -> V_23 . V_17 ) ;
F_17 ( V_146 == V_25 ) ;
F_114 ( V_25 , & V_41 ) ;
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
int V_25 = V_17 -> V_21 - 1 ;
V_17 = V_17 -> V_10 ;
if ( ! V_17 )
return NULL ;
if ( V_25 >= 0 ) {
V_17 = F_53 ( V_2 , V_17 , V_25 ) ;
if ( F_27 ( V_17 ) )
return V_17 ;
while ( V_17 -> V_34 != V_34 ) {
V_25 = V_17 -> V_36 - 1 ;
V_17 = F_53 ( V_2 , V_17 , V_25 ) ;
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
int V_25 = V_17 -> V_21 + 1 ;
V_17 = V_17 -> V_10 ;
if ( ! V_17 )
return NULL ;
if ( V_25 < V_17 -> V_36 ) {
V_17 = F_53 ( V_2 , V_17 , V_25 ) ;
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
union V_62 * V_47 , int V_34 ,
int V_3 , int V_4 )
{
struct V_16 * V_17 , * V_27 ;
int V_25 , V_74 ;
F_17 ( F_46 ( V_2 , V_47 ) < V_89 ) ;
if ( V_34 < 0 )
return F_14 ( - V_77 ) ;
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
F_67 ( V_2 , V_17 , V_47 , & V_25 ) ;
if ( V_25 < 0 ) {
V_17 = F_115 ( V_2 , V_17 ) ;
if ( ! V_17 )
return NULL ;
if ( F_27 ( V_17 ) )
return V_17 ;
F_67 ( V_2 , V_17 , V_47 , & V_25 ) ;
F_17 ( V_25 >= 0 ) ;
}
if ( V_17 -> V_34 == V_34 + 1 )
break;
V_17 = F_53 ( V_2 , V_17 , V_25 ) ;
if ( F_27 ( V_17 ) )
return V_17 ;
}
if ( V_17 -> V_20 [ V_25 ] . V_3 == V_3 && V_17 -> V_20 [ V_25 ] . V_4 == V_4 )
return F_53 ( V_2 , V_17 , V_25 ) ;
if ( ! F_29 ( V_2 , V_47 ) )
return NULL ;
V_27 = V_17 ;
V_74 = V_25 ;
while ( 1 ) {
if ( V_25 )
V_25 -= 1 ;
else {
V_17 = F_115 ( V_2 , V_17 ) ;
if ( ! V_17 )
break;
if ( F_27 ( V_17 ) )
return V_17 ;
V_25 = V_17 -> V_36 - 1 ;
}
if ( V_17 -> V_20 [ V_25 ] . V_3 == V_3 &&
V_17 -> V_20 [ V_25 ] . V_4 == V_4 )
return F_53 ( V_2 , V_17 , V_25 ) ;
if ( F_48 ( V_2 , & V_17 -> V_20 [ V_25 ] . V_47 , V_47 ) < 0 )
break;
}
V_17 = V_27 ;
V_25 = V_74 ;
while ( 1 ) {
if ( ++ V_25 >= V_17 -> V_36 ) {
V_17 = F_116 ( V_2 , V_17 ) ;
if ( ! V_17 )
break;
if ( F_27 ( V_17 ) )
return V_17 ;
V_25 = 0 ;
}
if ( V_17 -> V_20 [ V_25 ] . V_3 == V_3 &&
V_17 -> V_20 [ V_25 ] . V_4 == V_4 )
return F_53 ( V_2 , V_17 , V_25 ) ;
if ( F_48 ( V_2 , & V_17 -> V_20 [ V_25 ] . V_47 , V_47 ) > 0 )
break;
}
return NULL ;
}
int F_118 ( struct V_1 * V_2 , union V_62 * V_47 , int V_34 ,
int V_3 , int V_4 )
{
struct V_16 * V_17 ;
V_17 = F_117 ( V_2 , V_47 , V_34 , V_3 , V_4 ) ;
if ( ! V_17 )
return 0 ;
if ( F_27 ( V_17 ) )
return F_56 ( V_17 ) ;
return F_64 ( V_17 ) ? 1 : 2 ;
}
static int F_119 ( struct V_1 * V_2 , union V_62 * V_47 ,
int V_3 , int V_4 )
{
struct V_18 * V_19 ;
struct V_16 * V_17 , * V_27 ;
int V_25 , V_94 , V_24 , V_74 ;
const int V_149 = ! F_29 ( V_2 , V_47 ) ;
V_94 = F_65 ( V_2 , V_47 , & V_17 , & V_25 ) ;
if ( V_94 < 0 )
return V_94 ;
if ( ! V_94 )
return 0 ;
V_19 = & V_17 -> V_20 [ V_25 ] ;
if ( V_3 == V_19 -> V_3 && V_4 == V_19 -> V_4 )
return 1 ;
if ( V_149 )
return 0 ;
V_27 = V_17 ;
V_74 = V_25 ;
while ( 1 ) {
V_24 = F_57 ( V_2 , & V_17 , & V_25 ) ;
if ( V_24 == - V_76 )
break;
if ( V_24 )
return V_24 ;
if ( F_48 ( V_2 , V_47 , & V_17 -> V_20 [ V_25 ] . V_47 ) )
break;
V_19 = & V_17 -> V_20 [ V_25 ] ;
if ( V_3 == V_19 -> V_3 && V_4 == V_19 -> V_4 )
return 1 ;
}
V_17 = V_27 ;
V_25 = V_74 ;
while ( 1 ) {
V_24 = F_55 ( V_2 , & V_17 , & V_25 ) ;
if ( V_24 ) {
if ( V_24 == - V_76 )
return 0 ;
return V_24 ;
}
if ( F_48 ( V_2 , V_47 , & V_17 -> V_20 [ V_25 ] . V_47 ) )
break;
V_19 = & V_17 -> V_20 [ V_25 ] ;
if ( V_3 == V_19 -> V_3 && V_4 == V_19 -> V_4 )
return 1 ;
}
return 0 ;
}
int F_120 ( struct V_1 * V_2 , union V_62 * V_47 , int V_34 ,
int V_3 , int V_4 , int V_150 )
{
int V_24 ;
F_73 ( & V_2 -> V_98 ) ;
if ( V_150 ) {
V_24 = F_118 ( V_2 , V_47 , V_34 , V_3 , V_4 ) ;
if ( V_24 < 0 )
goto V_123;
if ( V_24 == 1 )
V_24 = 0 ;
else if ( V_24 == 2 )
V_24 = 1 ;
else
F_121 ( V_24 != 0 ) ;
} else
V_24 = F_119 ( V_2 , V_47 , V_3 , V_4 ) ;
V_123:
F_74 ( & V_2 -> V_98 ) ;
return V_24 ;
}
int F_122 ( struct V_1 * V_2 , union V_62 * V_47 , int V_34 ,
int V_3 , int V_4 )
{
struct V_16 * V_17 ;
int V_24 = 0 ;
F_73 ( & V_2 -> V_98 ) ;
V_17 = F_117 ( V_2 , V_47 , V_34 , V_3 , V_4 ) ;
if ( ! V_17 )
goto V_123;
if ( F_27 ( V_17 ) ) {
V_24 = F_56 ( V_17 ) ;
goto V_123;
}
V_17 = F_63 ( V_2 , V_17 ) ;
if ( F_27 ( V_17 ) ) {
V_24 = F_56 ( V_17 ) ;
goto V_123;
}
V_123:
F_74 ( & V_2 -> V_98 ) ;
return V_24 ;
}
int F_123 ( struct V_1 * V_2 , const struct V_151 * V_151 ,
T_3 V_152 )
{
int V_24 , V_25 ;
union V_62 V_135 , V_136 , * V_47 ;
struct V_16 * V_17 ;
unsigned int V_102 ;
if ( ! F_124 ( V_151 -> V_153 ) )
return 0 ;
if ( ! F_125 ( V_2 ) )
return 0 ;
V_102 = ( V_152 + V_154 - 1 ) >> V_155 ;
F_126 ( V_2 , & V_135 , V_151 -> V_156 , V_102 ) ;
F_127 ( V_2 , & V_136 , V_151 -> V_156 ) ;
F_73 ( & V_2 -> V_98 ) ;
V_24 = F_65 ( V_2 , & V_135 , & V_17 , & V_25 ) ;
if ( V_24 < 0 )
goto V_123;
if ( V_24 ) {
V_24 = - V_77 ;
V_47 = & V_135 ;
goto V_157;
}
V_24 = F_55 ( V_2 , & V_17 , & V_25 ) ;
if ( V_24 == - V_76 ) {
V_24 = 0 ;
goto V_123;
}
if ( V_24 < 0 )
goto V_123;
F_17 ( V_24 == 0 ) ;
V_47 = & V_17 -> V_20 [ V_25 ] . V_47 ;
if ( ! F_102 ( V_2 , V_47 , & V_135 , & V_136 ) )
goto V_123;
V_157:
V_102 = F_77 ( V_2 , V_47 ) ;
F_5 ( L_42 ,
( unsigned long ) V_151 -> V_156 , V_152 ,
( ( T_3 ) V_102 ) << V_155 ) ;
F_74 ( & V_2 -> V_98 ) ;
F_128 ( V_2 , V_151 ) ;
F_31 () ;
return - V_77 ;
V_123:
F_74 ( & V_2 -> V_98 ) ;
return V_24 ;
}
