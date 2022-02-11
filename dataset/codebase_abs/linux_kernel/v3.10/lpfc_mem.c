int
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
int V_7 ;
if ( V_2 -> V_8 == V_9 ) {
if ( V_2 -> V_10 < V_11 )
V_7 = V_2 -> V_10 ;
else
V_7 = V_11 ;
V_2 -> V_12 =
F_2 ( L_1 ,
V_2 -> V_13 ,
V_2 -> V_10 ,
V_7 ,
0 ) ;
} else {
V_2 -> V_12 =
F_2 ( L_1 ,
V_2 -> V_13 , V_2 -> V_10 ,
V_3 , 0 ) ;
}
if ( ! V_2 -> V_12 )
goto V_14;
V_2 -> V_15 = F_2 ( L_2 , V_2 -> V_13 ,
V_16 ,
V_3 , 0 ) ;
if ( ! V_2 -> V_15 )
goto V_17;
V_5 -> V_18 = F_3 ( sizeof( struct V_19 ) *
V_20 , V_21 ) ;
if ( ! V_5 -> V_18 )
goto V_22;
V_5 -> V_23 = 0 ;
V_5 -> V_24 = 0 ;
for ( V_7 = 0 ; V_7 < V_20 ; V_7 ++ ) {
V_5 -> V_18 [ V_7 ] . V_25 = F_4 ( V_2 -> V_15 ,
V_21 , & V_5 -> V_18 [ V_7 ] . V_26 ) ;
if ( ! V_5 -> V_18 [ V_7 ] . V_25 )
goto V_27;
V_5 -> V_23 ++ ;
V_5 -> V_24 ++ ;
}
V_2 -> V_28 = F_5 ( V_29 ,
sizeof( V_30 ) ) ;
if ( ! V_2 -> V_28 )
goto V_27;
V_2 -> V_31 = F_5 ( V_29 ,
sizeof( struct V_32 ) ) ;
if ( ! V_2 -> V_31 )
goto V_33;
if ( V_2 -> V_8 == V_9 ) {
V_2 -> V_34 =
F_5 ( V_29 ,
sizeof( struct V_35 ) ) ;
if ( ! V_2 -> V_34 )
goto V_36;
V_2 -> V_37 = F_2 ( L_3 ,
V_2 -> V_13 ,
V_38 , V_3 , 0 ) ;
if ( ! V_2 -> V_37 )
goto V_39;
V_2 -> V_40 = F_2 ( L_4 ,
V_2 -> V_13 ,
V_41 , V_3 , 0 ) ;
if ( ! V_2 -> V_40 )
goto V_42;
V_2 -> V_43 = NULL ;
} else {
V_2 -> V_43 = F_2 ( L_5 ,
V_2 -> V_13 , V_16 , V_3 , 0 ) ;
if ( ! V_2 -> V_43 )
goto V_36;
V_2 -> V_37 = NULL ;
V_2 -> V_40 = NULL ;
}
return 0 ;
V_42:
F_6 ( V_2 -> V_37 ) ;
V_2 -> V_37 = NULL ;
V_39:
F_7 ( V_2 -> V_34 ) ;
V_2 -> V_34 = NULL ;
V_36:
F_7 ( V_2 -> V_31 ) ;
V_2 -> V_31 = NULL ;
V_33:
F_7 ( V_2 -> V_28 ) ;
V_2 -> V_28 = NULL ;
V_27:
while ( V_7 -- )
F_8 ( V_2 -> V_15 , V_5 -> V_18 [ V_7 ] . V_25 ,
V_5 -> V_18 [ V_7 ] . V_26 ) ;
F_9 ( V_5 -> V_18 ) ;
V_22:
F_6 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
V_17:
F_6 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
V_14:
return - V_44 ;
}
void
F_10 ( struct V_1 * V_2 )
{
int V_7 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
F_11 ( V_2 ) ;
if ( V_2 -> V_40 )
F_6 ( V_2 -> V_40 ) ;
V_2 -> V_40 = NULL ;
if ( V_2 -> V_37 )
F_6 ( V_2 -> V_37 ) ;
V_2 -> V_37 = NULL ;
if ( V_2 -> V_43 )
F_6 ( V_2 -> V_43 ) ;
V_2 -> V_43 = NULL ;
if ( V_2 -> V_34 )
F_7 ( V_2 -> V_34 ) ;
V_2 -> V_34 = NULL ;
F_7 ( V_2 -> V_31 ) ;
V_2 -> V_31 = NULL ;
F_7 ( V_2 -> V_28 ) ;
V_2 -> V_28 = NULL ;
for ( V_7 = 0 ; V_7 < V_5 -> V_24 ; V_7 ++ )
F_8 ( V_2 -> V_15 , V_5 -> V_18 [ V_7 ] . V_25 ,
V_5 -> V_18 [ V_7 ] . V_26 ) ;
F_9 ( V_5 -> V_18 ) ;
F_6 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
F_6 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
return;
}
void
F_12 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = & V_2 -> V_47 ;
V_30 * V_48 , * V_49 ;
struct V_19 * V_50 ;
F_13 (mbox, next_mbox, &psli->mboxq, list) {
V_50 = (struct V_19 * ) ( V_48 -> V_51 ) ;
if ( V_50 ) {
F_14 ( V_2 , V_50 -> V_25 , V_50 -> V_26 ) ;
F_9 ( V_50 ) ;
}
F_15 ( & V_48 -> V_52 ) ;
F_16 ( V_48 , V_2 -> V_28 ) ;
}
F_13 (mbox, next_mbox, &psli->mboxq_cmpl, list) {
V_50 = (struct V_19 * ) ( V_48 -> V_51 ) ;
if ( V_50 ) {
F_14 ( V_2 , V_50 -> V_25 , V_50 -> V_26 ) ;
F_9 ( V_50 ) ;
}
F_15 ( & V_48 -> V_52 ) ;
F_16 ( V_48 , V_2 -> V_28 ) ;
}
F_17 ( & V_2 -> V_53 ) ;
V_46 -> V_54 &= ~ V_55 ;
F_18 ( & V_2 -> V_53 ) ;
if ( V_46 -> V_56 ) {
V_48 = V_46 -> V_56 ;
V_50 = (struct V_19 * ) ( V_48 -> V_51 ) ;
if ( V_50 ) {
F_14 ( V_2 , V_50 -> V_25 , V_50 -> V_26 ) ;
F_9 ( V_50 ) ;
}
F_16 ( V_48 , V_2 -> V_28 ) ;
V_46 -> V_56 = NULL ;
}
F_10 ( V_2 ) ;
F_9 ( V_46 -> V_57 ) ;
V_46 -> V_57 = NULL ;
return;
}
void *
F_19 ( struct V_1 * V_2 , int V_58 , T_1 * V_59 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
unsigned long V_60 ;
void * V_61 ;
V_61 = F_4 ( V_2 -> V_15 , V_21 , V_59 ) ;
F_20 ( & V_2 -> V_53 , V_60 ) ;
if ( ! V_61 && ( V_58 & V_62 ) && V_5 -> V_24 ) {
V_5 -> V_24 -- ;
V_61 = V_5 -> V_18 [ V_5 -> V_24 ] . V_25 ;
* V_59 = V_5 -> V_18 [ V_5 -> V_24 ] . V_26 ;
}
F_21 ( & V_2 -> V_53 , V_60 ) ;
return V_61 ;
}
void
F_22 ( struct V_1 * V_2 , void * V_25 , T_1 V_63 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
if ( V_5 -> V_24 < V_5 -> V_23 ) {
V_5 -> V_18 [ V_5 -> V_24 ] . V_25 = V_25 ;
V_5 -> V_18 [ V_5 -> V_24 ] . V_26 = V_63 ;
V_5 -> V_24 ++ ;
} else {
F_8 ( V_2 -> V_15 , V_25 , V_63 ) ;
}
return;
}
void
F_14 ( struct V_1 * V_2 , void * V_25 , T_1 V_63 )
{
unsigned long V_60 ;
F_20 ( & V_2 -> V_53 , V_60 ) ;
F_22 ( V_2 , V_25 , V_63 ) ;
F_21 ( & V_2 -> V_53 , V_60 ) ;
return;
}
struct V_64 *
F_23 ( struct V_1 * V_2 )
{
struct V_64 * V_65 ;
V_65 = F_24 ( sizeof( struct V_64 ) , V_21 ) ;
if ( ! V_65 )
return NULL ;
V_65 -> V_66 . V_25 = F_4 ( V_2 -> V_43 , V_21 ,
& V_65 -> V_66 . V_26 ) ;
if ( ! V_65 -> V_66 . V_25 ) {
F_9 ( V_65 ) ;
return NULL ;
}
V_65 -> V_67 = V_16 ;
return V_65 ;
}
void
F_25 ( struct V_1 * V_2 , struct V_64 * V_65 )
{
F_8 ( V_2 -> V_43 , V_65 -> V_66 . V_25 , V_65 -> V_66 . V_26 ) ;
F_9 ( V_65 ) ;
return;
}
struct V_64 *
F_26 ( struct V_1 * V_2 )
{
struct V_64 * V_68 ;
V_68 = F_24 ( sizeof( struct V_64 ) , V_21 ) ;
if ( ! V_68 )
return NULL ;
V_68 -> V_69 . V_25 = F_4 ( V_2 -> V_37 , V_21 ,
& V_68 -> V_69 . V_26 ) ;
if ( ! V_68 -> V_69 . V_25 ) {
F_9 ( V_68 ) ;
return NULL ;
}
V_68 -> V_66 . V_25 = F_4 ( V_2 -> V_40 , V_21 ,
& V_68 -> V_66 . V_26 ) ;
if ( ! V_68 -> V_66 . V_25 ) {
F_8 ( V_2 -> V_37 , V_68 -> V_69 . V_25 ,
V_68 -> V_69 . V_26 ) ;
F_9 ( V_68 ) ;
return NULL ;
}
V_68 -> V_67 = V_16 ;
return V_68 ;
}
void
F_27 ( struct V_1 * V_2 , struct V_64 * V_70 )
{
F_8 ( V_2 -> V_37 , V_70 -> V_69 . V_25 , V_70 -> V_69 . V_26 ) ;
F_8 ( V_2 -> V_40 , V_70 -> V_66 . V_25 , V_70 -> V_66 . V_26 ) ;
F_9 ( V_70 ) ;
return;
}
void
F_28 ( struct V_1 * V_2 , struct V_19 * V_50 )
{
struct V_64 * V_71 ;
unsigned long V_72 ;
if ( ! V_50 )
return;
if ( V_2 -> V_73 & V_74 ) {
F_20 ( & V_2 -> V_53 , V_72 ) ;
if ( ! V_2 -> V_75 ) {
F_21 ( & V_2 -> V_53 , V_72 ) ;
return;
}
V_71 = F_29 ( V_50 , struct V_64 , V_66 ) ;
F_15 ( & V_71 -> V_66 . V_52 ) ;
if ( V_71 -> V_76 == - 1 ) {
( V_2 -> V_77 [ V_78 ] . V_79 )
( V_2 , V_71 ) ;
} else {
F_30 ( V_2 , V_71 ) ;
}
F_21 ( & V_2 -> V_53 , V_72 ) ;
} else {
F_14 ( V_2 , V_50 -> V_25 , V_50 -> V_26 ) ;
F_9 ( V_50 ) ;
}
return;
}
