static struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 = NULL ;
F_2 ( & V_4 ) ;
F_3 (e, &ematch_ops, link) {
if ( V_2 == V_3 -> V_2 ) {
if ( ! F_4 ( V_3 -> V_5 ) )
V_3 = NULL ;
F_5 ( & V_4 ) ;
return V_3 ;
}
}
F_5 ( & V_4 ) ;
return NULL ;
}
int F_6 ( struct V_1 * V_6 )
{
int V_7 = - V_8 ;
struct V_1 * V_3 ;
if ( V_6 -> V_9 == NULL )
return - V_10 ;
F_7 ( & V_4 ) ;
F_3 (e, &ematch_ops, link)
if ( V_6 -> V_2 == V_3 -> V_2 )
goto V_11;
F_8 ( & V_6 -> V_12 , & V_13 ) ;
V_7 = 0 ;
V_11:
F_9 ( & V_4 ) ;
return V_7 ;
}
void F_10 ( struct V_1 * V_6 )
{
F_7 ( & V_4 ) ;
F_11 ( & V_6 -> V_12 ) ;
F_9 ( & V_4 ) ;
}
static inline struct V_14 * F_12 ( struct V_15 * V_16 ,
int V_17 )
{
return & V_16 -> V_18 [ V_17 ] ;
}
static int F_13 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_14 * V_23 , struct V_24 * V_25 , int V_26 )
{
int V_7 = - V_10 ;
struct V_27 * V_28 = F_14 ( V_25 ) ;
int V_29 = F_15 ( V_25 ) - sizeof( * V_28 ) ;
void * V_30 = ( void * ) V_28 + sizeof( * V_28 ) ;
struct V_31 * V_31 = F_16 ( F_17 ( V_20 -> V_32 ) ) ;
if ( ! F_18 ( V_28 -> V_33 ) )
goto V_11;
if ( V_28 -> V_2 == V_34 ) {
T_2 V_35 ;
if ( V_29 < sizeof( V_35 ) )
goto V_11;
V_35 = * ( T_2 * ) V_30 ;
if ( V_35 >= V_22 -> V_36 )
goto V_11;
if ( V_35 <= V_26 )
goto V_11;
V_23 -> V_30 = V_35 ;
} else {
V_23 -> V_6 = F_1 ( V_28 -> V_2 ) ;
if ( V_23 -> V_6 == NULL ) {
V_7 = - V_37 ;
#ifdef F_19
F_20 () ;
F_21 ( L_1 , V_28 -> V_2 ) ;
F_22 () ;
V_23 -> V_6 = F_1 ( V_28 -> V_2 ) ;
if ( V_23 -> V_6 ) {
F_23 ( V_23 -> V_6 -> V_5 ) ;
V_23 -> V_6 = NULL ;
V_7 = - V_38 ;
}
#endif
goto V_11;
}
if ( V_23 -> V_6 -> V_39 && V_29 < V_23 -> V_6 -> V_39 )
goto V_11;
if ( V_23 -> V_6 -> V_40 ) {
V_7 = V_23 -> V_6 -> V_40 ( V_31 , V_30 , V_29 , V_23 ) ;
if ( V_7 < 0 )
goto V_11;
} else if ( V_29 > 0 ) {
if ( V_28 -> V_33 & V_41 ) {
if ( V_29 < sizeof( T_2 ) )
goto V_11;
V_23 -> V_30 = * ( T_2 * ) V_30 ;
} else {
void * V_42 = F_24 ( V_30 , V_29 , V_43 ) ;
if ( V_42 == NULL ) {
V_7 = - V_44 ;
goto V_11;
}
V_23 -> V_30 = ( unsigned long ) V_42 ;
}
}
}
V_23 -> V_45 = V_28 -> V_45 ;
V_23 -> V_33 = V_28 -> V_33 ;
V_23 -> V_39 = V_29 ;
V_23 -> V_31 = V_31 ;
V_7 = 0 ;
V_11:
return V_7 ;
}
int F_25 ( struct V_19 * V_20 , struct V_24 * V_25 ,
struct V_15 * V_16 )
{
int V_26 , V_46 , V_47 , V_7 ;
struct V_24 * V_48 [ V_49 + 1 ] ;
struct V_24 * V_50 , * V_51 , * V_52 ;
struct V_21 * V_22 ;
struct V_14 * V_23 ;
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
if ( ! V_25 )
return 0 ;
V_7 = F_26 ( V_48 , V_49 , V_25 , V_53 , NULL ) ;
if ( V_7 < 0 )
goto V_11;
V_7 = - V_10 ;
V_51 = V_48 [ V_54 ] ;
V_52 = V_48 [ V_55 ] ;
if ( V_51 == NULL || V_52 == NULL )
goto V_11;
V_22 = F_14 ( V_51 ) ;
memcpy ( & V_16 -> V_56 , V_22 , sizeof( * V_22 ) ) ;
V_50 = F_14 ( V_52 ) ;
V_46 = F_15 ( V_52 ) ;
V_47 = V_22 -> V_36 * sizeof( * V_23 ) ;
V_16 -> V_18 = F_27 ( V_47 , V_43 ) ;
if ( V_16 -> V_18 == NULL )
goto V_11;
for ( V_26 = 0 ; F_28 ( V_50 , V_46 ) ; V_26 ++ ) {
V_7 = - V_10 ;
if ( V_50 -> V_57 != ( V_26 + 1 ) )
goto V_58;
if ( V_26 >= V_22 -> V_36 )
goto V_58;
if ( F_15 ( V_50 ) < sizeof( struct V_27 ) )
goto V_58;
V_23 = F_12 ( V_16 , V_26 ) ;
V_7 = F_13 ( V_20 , V_22 , V_23 , V_50 , V_26 ) ;
if ( V_7 < 0 )
goto V_58;
V_50 = F_29 ( V_50 , & V_46 ) ;
}
if ( V_26 != V_22 -> V_36 ) {
V_7 = - V_10 ;
goto V_58;
}
V_7 = 0 ;
V_11:
return V_7 ;
V_58:
F_30 ( V_16 ) ;
return V_7 ;
}
void F_30 ( struct V_15 * V_16 )
{
int V_59 ;
if ( V_16 -> V_18 == NULL )
return;
for ( V_59 = 0 ; V_59 < V_16 -> V_56 . V_36 ; V_59 ++ ) {
struct V_14 * V_23 = F_12 ( V_16 , V_59 ) ;
if ( V_23 -> V_6 ) {
if ( V_23 -> V_6 -> V_60 )
V_23 -> V_6 -> V_60 ( V_23 ) ;
else if ( ! F_31 ( V_23 ) )
F_32 ( ( void * ) V_23 -> V_30 ) ;
F_23 ( V_23 -> V_6 -> V_5 ) ;
}
}
V_16 -> V_56 . V_36 = 0 ;
F_32 ( V_16 -> V_18 ) ;
V_16 -> V_18 = NULL ;
}
int F_33 ( struct V_61 * V_62 , struct V_15 * V_16 , int V_63 )
{
int V_59 ;
T_3 * V_64 ;
struct V_24 * V_65 ;
struct V_24 * V_66 ;
V_65 = F_34 ( V_62 , V_63 ) ;
if ( V_65 == NULL )
goto V_67;
if ( F_35 ( V_62 , V_54 , sizeof( V_16 -> V_56 ) , & V_16 -> V_56 ) )
goto V_67;
V_66 = F_34 ( V_62 , V_55 ) ;
if ( V_66 == NULL )
goto V_67;
V_64 = F_36 ( V_62 ) ;
for ( V_59 = 0 ; V_59 < V_16 -> V_56 . V_36 ; V_59 ++ ) {
struct V_24 * V_68 = (struct V_24 * ) V_64 ;
struct V_14 * V_23 = F_12 ( V_16 , V_59 ) ;
struct V_27 V_28 = {
. V_2 = V_23 -> V_6 ? V_23 -> V_6 -> V_2 : V_34 ,
. V_45 = V_23 -> V_45 ,
. V_33 = V_23 -> V_33
} ;
if ( F_35 ( V_62 , V_59 + 1 , sizeof( V_28 ) , & V_28 ) )
goto V_67;
if ( V_23 -> V_6 && V_23 -> V_6 -> V_69 ) {
if ( V_23 -> V_6 -> V_69 ( V_62 , V_23 ) < 0 )
goto V_67;
} else if ( F_37 ( V_23 ) || F_31 ( V_23 ) ) {
T_2 V_70 = V_23 -> V_30 ;
F_38 ( V_62 , sizeof( V_70 ) , & V_70 ) ;
} else if ( V_23 -> V_39 > 0 )
F_38 ( V_62 , V_23 -> V_39 , ( void * ) V_23 -> V_30 ) ;
V_64 = F_36 ( V_62 ) ;
V_68 -> F_15 = V_64 - ( T_3 * ) V_68 ;
}
F_39 ( V_62 , V_66 ) ;
F_39 ( V_62 , V_65 ) ;
return 0 ;
V_67:
return - 1 ;
}
static inline int F_40 ( struct V_61 * V_62 , struct V_14 * V_23 ,
struct V_71 * V_72 )
{
int V_73 = V_23 -> V_6 -> V_9 ( V_62 , V_23 , V_72 ) ;
return F_41 ( V_23 ) ? ! V_73 : V_73 ;
}
int F_42 ( struct V_61 * V_62 , struct V_15 * V_16 ,
struct V_71 * V_72 )
{
int V_74 = 0 , V_75 = 0 , V_76 = 0 ;
struct V_14 * V_77 ;
int V_78 [ V_79 ] ;
V_80:
while ( V_75 < V_16 -> V_56 . V_36 ) {
V_77 = F_12 ( V_16 , V_75 ) ;
if ( F_37 ( V_77 ) ) {
if ( F_43 ( V_74 >= V_79 ) )
goto V_81;
V_78 [ V_74 ++ ] = V_75 ;
V_75 = V_77 -> V_30 ;
goto V_80;
}
V_76 = F_40 ( V_62 , V_77 , V_72 ) ;
if ( F_44 ( V_77 , V_76 ) )
break;
V_75 ++ ;
}
V_82:
if ( V_74 > 0 ) {
V_75 = V_78 [ -- V_74 ] ;
V_77 = F_12 ( V_16 , V_75 ) ;
if ( F_41 ( V_77 ) )
V_76 = ! V_76 ;
if ( F_44 ( V_77 , V_76 ) ) {
goto V_82;
} else {
V_75 ++ ;
goto V_80;
}
}
return V_76 ;
V_81:
F_45 ( L_2 ) ;
return - 1 ;
}
