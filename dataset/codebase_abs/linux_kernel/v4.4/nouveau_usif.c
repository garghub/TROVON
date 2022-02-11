static inline struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_5 ( V_3 ) ;
struct V_1 * V_7 ;
F_2 (ntfy, &cli->notifys, head) {
if ( V_7 -> V_4 == V_4 )
return V_7 ;
}
return NULL ;
}
static inline void
F_3 ( struct V_1 * V_7 )
{
F_4 ( & V_7 -> V_8 ) ;
F_5 ( V_7 ) ;
}
int
V_1 ( const void * V_9 , T_1 V_10 , const void * V_11 , T_1 V_12 )
{
struct V_1 * V_7 = NULL ;
const union {
struct V_13 V_14 ;
} * V_15 = V_9 ;
struct V_16 * V_17 ;
struct V_2 * V_3 ;
unsigned long V_18 ;
if ( V_10 == sizeof( V_15 -> V_14 ) && V_15 -> V_14 . V_19 == 0 ) {
if ( F_6 ( ! ( V_7 = ( void * ) ( unsigned long ) V_15 -> V_14 . V_20 ) ) )
return V_21 ;
F_7 ( V_15 -> V_14 . V_22 != V_23 ) ;
} else
if ( F_6 ( 1 ) )
return V_21 ;
if ( F_6 ( ! V_7 -> V_24 || V_7 -> V_25 != ( V_10 + V_12 ) ) )
return V_21 ;
V_3 = V_7 -> V_24 -> V_26 . V_27 ;
V_17 = V_3 -> V_28 -> V_17 ;
memcpy ( & V_7 -> V_24 -> V_29 . V_11 [ 0 ] , V_9 , V_10 ) ;
memcpy ( & V_7 -> V_24 -> V_29 . V_11 [ V_10 ] , V_11 , V_12 ) ;
switch ( V_15 -> V_14 . V_19 ) {
case 0 : {
struct V_13 * V_15 = ( void * ) V_7 -> V_24 -> V_29 . V_11 ;
V_15 -> V_22 = V_7 -> V_22 ;
V_15 -> V_20 = V_7 -> V_20 ;
}
break;
default:
F_7 ( 1 ) ;
break;
}
F_8 ( & V_17 -> V_30 , V_18 ) ;
if ( ! F_6 ( V_3 -> V_31 < V_7 -> V_24 -> V_29 . V_26 . V_10 ) ) {
F_9 ( & V_7 -> V_24 -> V_26 . V_32 , & V_3 -> V_33 ) ;
V_3 -> V_31 -= V_7 -> V_24 -> V_29 . V_26 . V_10 ;
}
F_10 ( & V_3 -> V_34 ) ;
F_11 ( & V_17 -> V_30 , V_18 ) ;
F_12 ( & V_7 -> V_35 , 0 ) ;
return V_21 ;
}
static int
F_13 ( struct V_2 * V_36 , void * V_11 , T_1 V_12 , void * V_37 , T_1 V_38 )
{
struct V_5 * V_6 = V_5 ( V_36 ) ;
struct V_39 * V_40 = & V_6 -> V_26 ;
union {
struct V_41 V_14 ;
} * args = V_11 ;
union {
struct V_42 V_14 ;
} * V_43 ;
struct V_1 * V_7 ;
int V_44 ;
if ( F_14 ( args -> V_14 , 0 , 0 , true ) ) {
if ( F_1 ( V_36 , args -> V_14 . V_45 ) )
return - V_46 ;
} else
return V_44 ;
V_43 = V_11 ;
if ( ! ( V_7 = F_15 ( sizeof( * V_7 ) , V_47 ) ) )
return - V_48 ;
F_12 ( & V_7 -> V_35 , 0 ) ;
if ( F_14 ( V_43 -> V_14 , 0 , 0 , true ) ) {
V_7 -> V_25 = sizeof( struct V_13 ) + V_43 -> V_14 . V_25 ;
V_7 -> V_22 = V_43 -> V_14 . V_22 ;
V_7 -> V_20 = V_43 -> V_14 . V_20 ;
V_43 -> V_14 . V_22 = V_23 ;
V_43 -> V_14 . V_20 = ( unsigned long ) ( void * ) V_7 ;
V_44 = F_16 ( V_40 , V_37 , V_38 ) ;
V_43 -> V_14 . V_20 = V_7 -> V_20 ;
V_43 -> V_14 . V_22 = V_7 -> V_22 ;
V_7 -> V_4 = args -> V_14 . V_45 ;
}
if ( V_44 == 0 )
F_17 ( & V_7 -> V_8 , & V_6 -> V_49 ) ;
if ( V_44 )
F_5 ( V_7 ) ;
return V_44 ;
}
static int
F_18 ( struct V_2 * V_36 , void * V_11 , T_1 V_12 , void * V_37 , T_1 V_38 )
{
struct V_5 * V_6 = V_5 ( V_36 ) ;
struct V_39 * V_40 = & V_6 -> V_26 ;
union {
struct V_50 V_14 ;
} * args = V_11 ;
struct V_1 * V_7 ;
int V_44 ;
if ( F_14 ( args -> V_14 , 0 , 0 , true ) ) {
if ( ! ( V_7 = F_1 ( V_36 , args -> V_14 . V_45 ) ) )
return - V_51 ;
} else
return V_44 ;
V_44 = F_16 ( V_40 , V_37 , V_38 ) ;
if ( V_44 == 0 )
F_3 ( V_7 ) ;
return V_44 ;
}
static int
F_19 ( struct V_2 * V_36 , void * V_11 , T_1 V_12 , void * V_37 , T_1 V_38 )
{
struct V_5 * V_6 = V_5 ( V_36 ) ;
struct V_39 * V_40 = & V_6 -> V_26 ;
union {
struct V_50 V_14 ;
} * args = V_11 ;
struct V_1 * V_7 ;
int V_44 ;
if ( F_14 ( args -> V_14 , 0 , 0 , true ) ) {
if ( ! ( V_7 = F_1 ( V_36 , args -> V_14 . V_45 ) ) )
return - V_51 ;
} else
return V_44 ;
if ( F_20 ( & V_7 -> V_35 , 1 ) )
return 0 ;
V_7 -> V_24 = F_15 ( sizeof( * V_7 -> V_24 ) + V_7 -> V_25 , V_47 ) ;
if ( V_44 = - V_48 , ! V_7 -> V_24 )
goto V_52;
V_7 -> V_24 -> V_26 . V_53 = & V_7 -> V_24 -> V_29 . V_26 ;
V_7 -> V_24 -> V_26 . V_27 = V_36 ;
V_7 -> V_24 -> V_26 . V_54 = V_55 -> V_54 ;
V_7 -> V_24 -> V_26 . V_56 = ( void ( * ) ( struct V_57 * ) ) F_5 ;
V_7 -> V_24 -> V_29 . V_26 . type = V_58 ;
V_7 -> V_24 -> V_29 . V_26 . V_10 = sizeof( V_7 -> V_24 -> V_29 . V_26 ) + V_7 -> V_25 ;
V_44 = F_16 ( V_40 , V_37 , V_38 ) ;
V_52:
if ( V_44 ) {
F_12 ( & V_7 -> V_35 , 0 ) ;
F_5 ( V_7 -> V_24 ) ;
}
return V_44 ;
}
static int
F_21 ( struct V_2 * V_36 , void * V_11 , T_1 V_12 , void * V_37 , T_1 V_38 )
{
struct V_5 * V_6 = V_5 ( V_36 ) ;
struct V_39 * V_40 = & V_6 -> V_26 ;
union {
struct V_59 V_14 ;
} * args = V_11 ;
struct V_1 * V_7 ;
int V_44 ;
if ( F_14 ( args -> V_14 , 0 , 0 , true ) ) {
if ( ! ( V_7 = F_1 ( V_36 , args -> V_14 . V_45 ) ) )
return - V_51 ;
} else
return V_44 ;
V_44 = F_16 ( V_40 , V_37 , V_38 ) ;
if ( V_44 == 0 && F_20 ( & V_7 -> V_35 , 0 ) )
F_5 ( V_7 -> V_24 ) ;
return V_44 ;
}
static void
F_22 ( struct V_60 * V_61 )
{
F_4 ( & V_61 -> V_8 ) ;
F_5 ( V_61 ) ;
}
static int
F_23 ( struct V_2 * V_36 , void * V_11 , T_1 V_12 , void * V_37 , T_1 V_38 )
{
struct V_5 * V_6 = V_5 ( V_36 ) ;
struct V_39 * V_40 = & V_6 -> V_26 ;
union {
struct V_62 V_14 ;
} * args = V_11 ;
struct V_60 * V_61 ;
int V_44 ;
if ( ! ( V_61 = F_15 ( sizeof( * V_61 ) , V_47 ) ) )
return - V_48 ;
F_17 ( & V_61 -> V_8 , & V_6 -> V_63 ) ;
if ( F_14 ( args -> V_14 , 0 , 0 , true ) ) {
V_61 -> V_22 = args -> V_14 . V_22 ;
V_61 -> V_20 = args -> V_14 . V_20 ;
args -> V_14 . V_22 = V_64 ;
args -> V_14 . V_20 = ( unsigned long ) ( void * ) V_61 ;
V_44 = F_16 ( V_40 , V_37 , V_38 ) ;
args -> V_14 . V_20 = V_61 -> V_20 ;
args -> V_14 . V_22 = V_61 -> V_22 ;
}
if ( V_44 )
F_22 ( V_61 ) ;
return V_44 ;
}
int
F_24 ( struct V_2 * V_3 , void T_2 * V_65 , T_1 V_38 )
{
struct V_5 * V_6 = V_5 ( V_3 ) ;
struct V_39 * V_40 = & V_6 -> V_26 ;
void * V_11 = F_15 ( V_38 , V_47 ) ;
T_1 V_12 = V_38 ;
union {
struct V_66 V_14 ;
} * V_37 = V_11 ;
struct V_60 * V_61 ;
T_3 V_67 ;
int V_44 ;
if ( V_44 = - V_48 , ! V_37 )
goto V_52;
if ( V_44 = - V_68 , F_25 ( V_37 , V_65 , V_12 ) )
goto V_52;
if ( F_14 ( V_37 -> V_14 , 0 , 0 , true ) ) {
V_67 = V_37 -> V_14 . V_67 ;
if ( V_37 -> V_14 . V_61 == 0ULL )
V_37 -> V_14 . V_67 = V_69 ;
else
V_37 -> V_14 . V_67 = V_64 ;
} else
goto V_52;
F_26 ( & V_6 -> V_70 ) ;
if ( V_37 -> V_14 . V_22 ) {
if ( V_44 = - V_71 , V_37 -> V_14 . V_22 == 0xff )
V_44 = F_27 ( V_3 , V_37 , V_38 ) ;
if ( V_44 ) {
F_28 ( & V_6 -> V_70 ) ;
goto V_52;
}
}
switch ( V_37 -> V_14 . type ) {
case V_72 :
V_44 = F_23 ( V_3 , V_11 , V_12 , V_37 , V_38 ) ;
break;
case V_73 :
V_44 = F_13 ( V_3 , V_11 , V_12 , V_37 , V_38 ) ;
break;
case V_74 :
V_44 = F_18 ( V_3 , V_11 , V_12 , V_37 , V_38 ) ;
break;
case V_75 :
V_44 = F_19 ( V_3 , V_11 , V_12 , V_37 , V_38 ) ;
break;
case V_76 :
V_44 = F_21 ( V_3 , V_11 , V_12 , V_37 , V_38 ) ;
break;
default:
V_44 = F_16 ( V_40 , V_37 , V_38 ) ;
break;
}
if ( V_37 -> V_14 . V_22 == V_64 ) {
V_61 = ( void * ) ( unsigned long ) V_37 -> V_14 . V_20 ;
V_37 -> V_14 . V_22 = V_61 -> V_22 ;
V_37 -> V_14 . V_20 = V_61 -> V_20 ;
if ( V_44 == 0 && V_37 -> V_14 . type == V_77 ) {
F_4 ( & V_61 -> V_8 ) ;
F_5 ( V_61 ) ;
}
} else {
V_37 -> V_14 . V_22 = V_78 ;
V_37 -> V_14 . V_20 = 0 ;
}
V_37 -> V_14 . V_67 = V_67 ;
F_28 ( & V_6 -> V_70 ) ;
if ( F_29 ( V_65 , V_37 , V_38 ) )
V_44 = - V_68 ;
V_52:
F_5 ( V_37 ) ;
return V_44 ;
}
void
F_30 ( struct V_5 * V_6 )
{
struct V_60 * V_61 , * V_79 ;
struct V_1 * V_80 , * V_81 ;
F_31 (notify, ntemp, &cli->notifys, head) {
F_3 ( V_80 ) ;
}
F_31 (object, otemp, &cli->objects, head) {
F_22 ( V_61 ) ;
}
}
void
F_32 ( struct V_5 * V_6 )
{
F_33 ( & V_6 -> V_63 ) ;
F_33 ( & V_6 -> V_49 ) ;
}
