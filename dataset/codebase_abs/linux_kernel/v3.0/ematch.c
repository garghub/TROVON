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
if ( ! F_16 ( V_28 -> V_31 ) )
goto V_11;
if ( V_28 -> V_2 == V_32 ) {
T_2 V_33 ;
if ( V_29 < sizeof( V_33 ) )
goto V_11;
V_33 = * ( T_2 * ) V_30 ;
if ( V_33 >= V_22 -> V_34 )
goto V_11;
if ( V_33 <= V_26 )
goto V_11;
V_23 -> V_30 = V_33 ;
} else {
V_23 -> V_6 = F_1 ( V_28 -> V_2 ) ;
if ( V_23 -> V_6 == NULL ) {
V_7 = - V_35 ;
#ifdef F_17
F_18 () ;
F_19 ( L_1 , V_28 -> V_2 ) ;
F_20 () ;
V_23 -> V_6 = F_1 ( V_28 -> V_2 ) ;
if ( V_23 -> V_6 ) {
F_21 ( V_23 -> V_6 -> V_5 ) ;
V_7 = - V_36 ;
}
#endif
goto V_11;
}
if ( V_23 -> V_6 -> V_37 && V_29 < V_23 -> V_6 -> V_37 )
goto V_11;
if ( V_23 -> V_6 -> V_38 ) {
V_7 = V_23 -> V_6 -> V_38 ( V_20 , V_30 , V_29 , V_23 ) ;
if ( V_7 < 0 )
goto V_11;
} else if ( V_29 > 0 ) {
if ( V_28 -> V_31 & V_39 ) {
if ( V_29 < sizeof( T_2 ) )
goto V_11;
V_23 -> V_30 = * ( T_2 * ) V_30 ;
} else {
void * V_40 = F_22 ( V_30 , V_29 , V_41 ) ;
if ( V_40 == NULL ) {
V_7 = - V_42 ;
goto V_11;
}
V_23 -> V_30 = ( unsigned long ) V_40 ;
}
}
}
V_23 -> V_43 = V_28 -> V_43 ;
V_23 -> V_31 = V_28 -> V_31 ;
V_23 -> V_37 = V_29 ;
V_7 = 0 ;
V_11:
return V_7 ;
}
int F_23 ( struct V_19 * V_20 , struct V_24 * V_25 ,
struct V_15 * V_16 )
{
int V_26 , V_44 , V_45 , V_7 ;
struct V_24 * V_46 [ V_47 + 1 ] ;
struct V_24 * V_48 , * V_49 , * V_50 ;
struct V_21 * V_22 ;
struct V_14 * V_23 ;
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
if ( ! V_25 )
return 0 ;
V_7 = F_24 ( V_46 , V_47 , V_25 , V_51 ) ;
if ( V_7 < 0 )
goto V_11;
V_7 = - V_10 ;
V_49 = V_46 [ V_52 ] ;
V_50 = V_46 [ V_53 ] ;
if ( V_49 == NULL || V_50 == NULL )
goto V_11;
V_22 = F_14 ( V_49 ) ;
memcpy ( & V_16 -> V_54 , V_22 , sizeof( * V_22 ) ) ;
V_48 = F_14 ( V_50 ) ;
V_44 = F_15 ( V_50 ) ;
V_45 = V_22 -> V_34 * sizeof( * V_23 ) ;
V_16 -> V_18 = F_25 ( V_45 , V_41 ) ;
if ( V_16 -> V_18 == NULL )
goto V_11;
for ( V_26 = 0 ; F_26 ( V_48 , V_44 ) ; V_26 ++ ) {
V_7 = - V_10 ;
if ( V_48 -> V_55 != ( V_26 + 1 ) )
goto V_56;
if ( V_26 >= V_22 -> V_34 )
goto V_56;
if ( F_15 ( V_48 ) < sizeof( struct V_27 ) )
goto V_56;
V_23 = F_12 ( V_16 , V_26 ) ;
V_7 = F_13 ( V_20 , V_22 , V_23 , V_48 , V_26 ) ;
if ( V_7 < 0 )
goto V_56;
V_48 = F_27 ( V_48 , & V_44 ) ;
}
if ( V_26 != V_22 -> V_34 ) {
V_7 = - V_10 ;
goto V_56;
}
V_7 = 0 ;
V_11:
return V_7 ;
V_56:
F_28 ( V_20 , V_16 ) ;
return V_7 ;
}
void F_28 ( struct V_19 * V_20 , struct V_15 * V_16 )
{
int V_57 ;
if ( V_16 -> V_18 == NULL )
return;
for ( V_57 = 0 ; V_57 < V_16 -> V_54 . V_34 ; V_57 ++ ) {
struct V_14 * V_23 = F_12 ( V_16 , V_57 ) ;
if ( V_23 -> V_6 ) {
if ( V_23 -> V_6 -> V_58 )
V_23 -> V_6 -> V_58 ( V_20 , V_23 ) ;
else if ( ! F_29 ( V_23 ) )
F_30 ( ( void * ) V_23 -> V_30 ) ;
F_21 ( V_23 -> V_6 -> V_5 ) ;
}
}
V_16 -> V_54 . V_34 = 0 ;
F_30 ( V_16 -> V_18 ) ;
V_16 -> V_18 = NULL ;
}
int F_31 ( struct V_59 * V_60 , struct V_15 * V_16 , int V_61 )
{
int V_57 ;
T_3 * V_62 ;
struct V_24 * V_63 ;
struct V_24 * V_64 ;
V_63 = F_32 ( V_60 , V_61 ) ;
if ( V_63 == NULL )
goto V_65;
F_33 ( V_60 , V_52 , sizeof( V_16 -> V_54 ) , & V_16 -> V_54 ) ;
V_64 = F_32 ( V_60 , V_53 ) ;
if ( V_64 == NULL )
goto V_65;
V_62 = F_34 ( V_60 ) ;
for ( V_57 = 0 ; V_57 < V_16 -> V_54 . V_34 ; V_57 ++ ) {
struct V_24 * V_66 = (struct V_24 * ) V_62 ;
struct V_14 * V_23 = F_12 ( V_16 , V_57 ) ;
struct V_27 V_28 = {
. V_2 = V_23 -> V_6 ? V_23 -> V_6 -> V_2 : V_32 ,
. V_43 = V_23 -> V_43 ,
. V_31 = V_23 -> V_31
} ;
F_33 ( V_60 , V_57 + 1 , sizeof( V_28 ) , & V_28 ) ;
if ( V_23 -> V_6 && V_23 -> V_6 -> V_67 ) {
if ( V_23 -> V_6 -> V_67 ( V_60 , V_23 ) < 0 )
goto V_65;
} else if ( F_35 ( V_23 ) || F_29 ( V_23 ) ) {
T_2 V_68 = V_23 -> V_30 ;
F_36 ( V_60 , sizeof( V_68 ) , & V_68 ) ;
} else if ( V_23 -> V_37 > 0 )
F_36 ( V_60 , V_23 -> V_37 , ( void * ) V_23 -> V_30 ) ;
V_62 = F_34 ( V_60 ) ;
V_66 -> F_15 = V_62 - ( T_3 * ) V_66 ;
}
F_37 ( V_60 , V_64 ) ;
F_37 ( V_60 , V_63 ) ;
return 0 ;
V_65:
return - 1 ;
}
static inline int F_38 ( struct V_59 * V_60 , struct V_14 * V_23 ,
struct V_69 * V_70 )
{
int V_71 = V_23 -> V_6 -> V_9 ( V_60 , V_23 , V_70 ) ;
return F_39 ( V_23 ) ? ! V_71 : V_71 ;
}
int F_40 ( struct V_59 * V_60 , struct V_15 * V_16 ,
struct V_69 * V_70 )
{
int V_72 = 0 , V_73 = 0 , V_74 = 0 ;
struct V_14 * V_75 ;
int V_76 [ V_77 ] ;
V_78:
while ( V_73 < V_16 -> V_54 . V_34 ) {
V_75 = F_12 ( V_16 , V_73 ) ;
if ( F_35 ( V_75 ) ) {
if ( F_41 ( V_72 >= V_77 ) )
goto V_79;
V_76 [ V_72 ++ ] = V_73 ;
V_73 = V_75 -> V_30 ;
goto V_78;
}
V_74 = F_38 ( V_60 , V_75 , V_70 ) ;
if ( F_42 ( V_75 , V_74 ) )
break;
V_73 ++ ;
}
V_80:
if ( V_72 > 0 ) {
V_73 = V_76 [ -- V_72 ] ;
V_75 = F_12 ( V_16 , V_73 ) ;
if ( F_42 ( V_75 , V_74 ) )
goto V_80;
else {
V_73 ++ ;
goto V_78;
}
}
return V_74 ;
V_79:
if ( F_43 () )
F_44 ( L_2
L_3 ) ;
return - 1 ;
}
