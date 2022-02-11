int
F_1 ( struct V_1 * V_2 ) {
T_1 V_3 ;
int V_4 = V_2 -> V_5 . V_6 . V_4 ;
if ( V_4 <= 0 )
return - V_7 ;
V_3 = ( ( V_8 - 1 + V_4 ) / V_8 ) *
sizeof( unsigned long ) ;
V_2 -> V_9 = V_3 ;
V_2 -> V_10 = F_2 ( V_11 ,
V_3 ) ;
if ( ! V_2 -> V_10 )
return - V_7 ;
else
return 0 ;
}
int
F_3 ( struct V_1 * V_2 , int V_12 )
{
struct V_13 * V_14 = & V_2 -> V_15 ;
int V_16 ;
if ( V_2 -> V_17 == V_18 ) {
if ( V_2 -> V_19 < V_20 )
V_16 = V_2 -> V_19 ;
else
V_16 = V_20 ;
V_2 -> V_21 =
F_4 ( L_1 ,
V_2 -> V_22 ,
V_2 -> V_19 ,
V_16 ,
0 ) ;
} else {
V_2 -> V_21 =
F_4 ( L_1 ,
V_2 -> V_22 , V_2 -> V_19 ,
V_12 , 0 ) ;
}
if ( ! V_2 -> V_21 )
goto V_23;
V_2 -> V_24 = F_4 ( L_2 , V_2 -> V_22 ,
V_25 ,
V_12 , 0 ) ;
if ( ! V_2 -> V_24 )
goto V_26;
V_14 -> V_27 = F_5 ( sizeof( struct V_28 ) *
V_29 , V_30 ) ;
if ( ! V_14 -> V_27 )
goto V_31;
V_14 -> V_32 = 0 ;
V_14 -> V_33 = 0 ;
for ( V_16 = 0 ; V_16 < V_29 ; V_16 ++ ) {
V_14 -> V_27 [ V_16 ] . V_34 = F_6 ( V_2 -> V_24 ,
V_30 , & V_14 -> V_27 [ V_16 ] . V_35 ) ;
if ( ! V_14 -> V_27 [ V_16 ] . V_34 )
goto V_36;
V_14 -> V_32 ++ ;
V_14 -> V_33 ++ ;
}
V_2 -> V_37 = F_2 ( V_11 ,
sizeof( V_38 ) ) ;
if ( ! V_2 -> V_37 )
goto V_36;
V_2 -> V_39 = F_2 ( V_11 ,
sizeof( struct V_40 ) ) ;
if ( ! V_2 -> V_39 )
goto V_41;
if ( V_2 -> V_17 == V_18 ) {
V_2 -> V_42 =
F_2 ( V_11 ,
sizeof( struct V_43 ) ) ;
if ( ! V_2 -> V_42 )
goto V_44;
V_2 -> V_45 = F_4 ( L_3 ,
V_2 -> V_22 ,
V_46 , V_12 , 0 ) ;
if ( ! V_2 -> V_45 )
goto V_47;
V_2 -> V_48 = F_4 ( L_4 ,
V_2 -> V_22 ,
V_49 , V_12 , 0 ) ;
if ( ! V_2 -> V_48 )
goto V_50;
V_2 -> V_51 = NULL ;
} else {
V_2 -> V_51 = F_4 ( L_5 ,
V_2 -> V_22 , V_25 , V_12 , 0 ) ;
if ( ! V_2 -> V_51 )
goto V_44;
V_2 -> V_45 = NULL ;
V_2 -> V_48 = NULL ;
}
if ( V_2 -> V_52 ) {
V_2 -> V_53 = F_2 (
V_54 ,
sizeof( struct V_55 ) ) ;
if ( ! V_2 -> V_53 )
goto V_50;
} else {
V_2 -> V_53 = NULL ;
}
return 0 ;
V_50:
F_7 ( V_2 -> V_45 ) ;
V_2 -> V_45 = NULL ;
V_47:
F_8 ( V_2 -> V_42 ) ;
V_2 -> V_42 = NULL ;
V_44:
F_8 ( V_2 -> V_39 ) ;
V_2 -> V_39 = NULL ;
V_41:
F_8 ( V_2 -> V_37 ) ;
V_2 -> V_37 = NULL ;
V_36:
while ( V_16 -- )
F_9 ( V_2 -> V_24 , V_14 -> V_27 [ V_16 ] . V_34 ,
V_14 -> V_27 [ V_16 ] . V_35 ) ;
F_10 ( V_14 -> V_27 ) ;
V_31:
F_7 ( V_2 -> V_24 ) ;
V_2 -> V_24 = NULL ;
V_26:
F_7 ( V_2 -> V_21 ) ;
V_2 -> V_21 = NULL ;
V_23:
return - V_7 ;
}
void
F_11 ( struct V_1 * V_2 )
{
int V_16 ;
struct V_13 * V_14 = & V_2 -> V_15 ;
struct V_55 * V_56 ;
F_12 ( V_2 ) ;
if ( V_2 -> V_48 )
F_7 ( V_2 -> V_48 ) ;
V_2 -> V_48 = NULL ;
if ( V_2 -> V_45 )
F_7 ( V_2 -> V_45 ) ;
V_2 -> V_45 = NULL ;
if ( V_2 -> V_51 )
F_7 ( V_2 -> V_51 ) ;
V_2 -> V_51 = NULL ;
F_8 ( V_2 -> V_42 ) ;
V_2 -> V_42 = NULL ;
F_8 ( V_2 -> V_39 ) ;
V_2 -> V_39 = NULL ;
if ( V_2 -> V_17 == V_18 ) {
F_8 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
}
F_8 ( V_2 -> V_37 ) ;
V_2 -> V_37 = NULL ;
for ( V_16 = 0 ; V_16 < V_14 -> V_33 ; V_16 ++ )
F_9 ( V_2 -> V_24 , V_14 -> V_27 [ V_16 ] . V_34 ,
V_14 -> V_27 [ V_16 ] . V_35 ) ;
F_10 ( V_14 -> V_27 ) ;
F_7 ( V_2 -> V_24 ) ;
V_2 -> V_24 = NULL ;
F_7 ( V_2 -> V_21 ) ;
V_2 -> V_21 = NULL ;
if ( V_2 -> V_53 ) {
while ( ! F_13 ( & V_2 -> V_57 ) ) {
V_56 = F_14 ( & V_2 -> V_57 ,
struct V_55 ,
V_58 ) ;
F_15 ( & V_56 -> V_58 ) ;
F_16 ( V_56 , V_2 -> V_53 ) ;
}
F_8 ( V_2 -> V_53 ) ;
}
V_2 -> V_53 = NULL ;
return;
}
void
F_17 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = & V_2 -> V_61 ;
V_38 * V_62 , * V_63 ;
struct V_28 * V_64 ;
F_18 (mbox, next_mbox, &psli->mboxq, list) {
V_64 = (struct V_28 * ) ( V_62 -> V_65 ) ;
if ( V_64 ) {
F_19 ( V_2 , V_64 -> V_34 , V_64 -> V_35 ) ;
F_10 ( V_64 ) ;
}
F_15 ( & V_62 -> V_66 ) ;
F_16 ( V_62 , V_2 -> V_37 ) ;
}
F_18 (mbox, next_mbox, &psli->mboxq_cmpl, list) {
V_64 = (struct V_28 * ) ( V_62 -> V_65 ) ;
if ( V_64 ) {
F_19 ( V_2 , V_64 -> V_34 , V_64 -> V_35 ) ;
F_10 ( V_64 ) ;
}
F_15 ( & V_62 -> V_66 ) ;
F_16 ( V_62 , V_2 -> V_37 ) ;
}
F_20 ( & V_2 -> V_67 ) ;
V_60 -> V_68 &= ~ V_69 ;
F_21 ( & V_2 -> V_67 ) ;
if ( V_60 -> V_70 ) {
V_62 = V_60 -> V_70 ;
V_64 = (struct V_28 * ) ( V_62 -> V_65 ) ;
if ( V_64 ) {
F_19 ( V_2 , V_64 -> V_34 , V_64 -> V_35 ) ;
F_10 ( V_64 ) ;
}
F_16 ( V_62 , V_2 -> V_37 ) ;
V_60 -> V_70 = NULL ;
}
F_11 ( V_2 ) ;
F_10 ( V_60 -> V_71 ) ;
V_60 -> V_71 = NULL ;
return;
}
void *
F_22 ( struct V_1 * V_2 , int V_72 , T_2 * V_73 )
{
struct V_13 * V_14 = & V_2 -> V_15 ;
unsigned long V_74 ;
void * V_75 ;
V_75 = F_6 ( V_2 -> V_24 , V_30 , V_73 ) ;
F_23 ( & V_2 -> V_67 , V_74 ) ;
if ( ! V_75 && ( V_72 & V_76 ) && V_14 -> V_33 ) {
V_14 -> V_33 -- ;
V_75 = V_14 -> V_27 [ V_14 -> V_33 ] . V_34 ;
* V_73 = V_14 -> V_27 [ V_14 -> V_33 ] . V_35 ;
}
F_24 ( & V_2 -> V_67 , V_74 ) ;
return V_75 ;
}
void
F_25 ( struct V_1 * V_2 , void * V_34 , T_2 V_77 )
{
struct V_13 * V_14 = & V_2 -> V_15 ;
if ( V_14 -> V_33 < V_14 -> V_32 ) {
V_14 -> V_27 [ V_14 -> V_33 ] . V_34 = V_34 ;
V_14 -> V_27 [ V_14 -> V_33 ] . V_35 = V_77 ;
V_14 -> V_33 ++ ;
} else {
F_9 ( V_2 -> V_24 , V_34 , V_77 ) ;
}
return;
}
void
F_19 ( struct V_1 * V_2 , void * V_34 , T_2 V_77 )
{
unsigned long V_74 ;
F_23 ( & V_2 -> V_67 , V_74 ) ;
F_25 ( V_2 , V_34 , V_77 ) ;
F_24 ( & V_2 -> V_67 , V_74 ) ;
return;
}
struct V_78 *
F_26 ( struct V_1 * V_2 )
{
struct V_78 * V_79 ;
V_79 = F_27 ( sizeof( struct V_78 ) , V_30 ) ;
if ( ! V_79 )
return NULL ;
V_79 -> V_80 . V_34 = F_6 ( V_2 -> V_51 , V_30 ,
& V_79 -> V_80 . V_35 ) ;
if ( ! V_79 -> V_80 . V_34 ) {
F_10 ( V_79 ) ;
return NULL ;
}
V_79 -> V_81 = V_25 ;
return V_79 ;
}
void
F_28 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
F_9 ( V_2 -> V_51 , V_79 -> V_80 . V_34 , V_79 -> V_80 . V_35 ) ;
F_10 ( V_79 ) ;
return;
}
struct V_78 *
F_29 ( struct V_1 * V_2 )
{
struct V_78 * V_82 ;
V_82 = F_27 ( sizeof( struct V_78 ) , V_30 ) ;
if ( ! V_82 )
return NULL ;
V_82 -> V_83 . V_34 = F_6 ( V_2 -> V_45 , V_30 ,
& V_82 -> V_83 . V_35 ) ;
if ( ! V_82 -> V_83 . V_34 ) {
F_10 ( V_82 ) ;
return NULL ;
}
V_82 -> V_80 . V_34 = F_6 ( V_2 -> V_48 , V_30 ,
& V_82 -> V_80 . V_35 ) ;
if ( ! V_82 -> V_80 . V_34 ) {
F_9 ( V_2 -> V_45 , V_82 -> V_83 . V_34 ,
V_82 -> V_83 . V_35 ) ;
F_10 ( V_82 ) ;
return NULL ;
}
V_82 -> V_81 = V_25 ;
return V_82 ;
}
void
F_30 ( struct V_1 * V_2 , struct V_78 * V_84 )
{
F_9 ( V_2 -> V_45 , V_84 -> V_83 . V_34 , V_84 -> V_83 . V_35 ) ;
F_9 ( V_2 -> V_48 , V_84 -> V_80 . V_34 , V_84 -> V_80 . V_35 ) ;
F_10 ( V_84 ) ;
return;
}
void
F_31 ( struct V_1 * V_2 , struct V_28 * V_64 )
{
struct V_78 * V_85 ;
unsigned long V_86 ;
if ( ! V_64 )
return;
if ( V_2 -> V_87 & V_88 ) {
F_23 ( & V_2 -> V_67 , V_86 ) ;
if ( ! V_2 -> V_89 ) {
F_24 ( & V_2 -> V_67 , V_86 ) ;
return;
}
V_85 = F_32 ( V_64 , struct V_78 , V_80 ) ;
F_15 ( & V_85 -> V_80 . V_66 ) ;
if ( V_85 -> V_90 == - 1 ) {
( V_2 -> V_91 [ V_92 ] . V_93 )
( V_2 , V_85 ) ;
} else {
F_33 ( V_2 , V_85 ) ;
}
F_24 ( & V_2 -> V_67 , V_86 ) ;
} else {
F_19 ( V_2 , V_64 -> V_34 , V_64 -> V_35 ) ;
F_10 ( V_64 ) ;
}
return;
}
