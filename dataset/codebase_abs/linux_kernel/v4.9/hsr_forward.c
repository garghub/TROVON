static bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
F_2 ( ! F_3 ( V_4 ) ) ;
V_6 = (struct V_5 * ) F_4 ( V_4 ) ;
if ( ! F_5 ( V_6 -> V_11 ,
V_2 -> V_12 ) )
return false ;
if ( ! ( V_6 -> V_13 == F_6 ( V_14 )
|| V_6 -> V_13 == F_6 ( V_15 ) ) )
return false ;
if ( V_6 -> V_13 == F_6 ( V_15 ) ) {
V_10 = (struct V_9 * ) F_4 ( V_4 ) ;
if ( V_10 -> V_2 . V_16 != F_6 ( V_14 ) )
return false ;
V_8 = & V_10 -> V_17 ;
} else {
V_8 = & ( (struct V_18 * ) F_4 ( V_4 ) ) -> V_17 ;
}
if ( ( V_8 -> V_19 != V_20 ) &&
( V_8 -> V_19 != V_21 ) )
return false ;
if ( ( V_8 -> V_22 != 12 ) &&
( V_8 -> V_22 !=
sizeof( struct V_23 ) ) )
return false ;
return true ;
}
static struct V_3 * F_7 ( struct V_3 * V_24 ,
struct V_25 * V_26 )
{
struct V_3 * V_4 ;
int V_27 ;
unsigned char * V_28 , * V_29 ;
F_8 ( V_24 , V_30 ) ;
V_4 = F_9 ( V_24 , F_10 ( V_24 ) - V_30 , V_31 ) ;
F_11 ( V_24 , V_30 ) ;
if ( V_4 == NULL )
return NULL ;
F_12 ( V_4 ) ;
if ( V_4 -> V_32 == V_33 )
V_4 -> V_34 -= V_30 ;
V_27 = 2 * V_35 ;
if ( V_26 -> V_36 )
V_27 += V_37 ;
V_29 = F_4 ( V_24 ) ;
V_28 = F_4 ( V_4 ) ;
memcpy ( V_28 , V_29 , V_27 ) ;
V_4 -> V_38 = F_13 ( V_4 ) -> V_13 ;
return V_4 ;
}
static struct V_3 * F_14 ( struct V_25 * V_26 ,
struct V_39 * V_40 )
{
if ( ! V_26 -> V_41 )
V_26 -> V_41 = F_7 ( V_26 -> V_42 , V_26 ) ;
return F_15 ( V_26 -> V_41 , V_31 ) ;
}
static void F_16 ( struct V_3 * V_4 , struct V_25 * V_26 ,
struct V_39 * V_40 , T_1 V_43 )
{
struct V_44 * V_44 ;
int V_45 ;
int V_46 ;
if ( V_40 -> type == V_47 )
V_45 = 0 ;
else
V_45 = 1 ;
V_46 = V_4 -> V_48 - 14 ;
if ( V_26 -> V_36 )
V_46 -= 4 ;
V_44 = (struct V_44 * ) F_4 ( V_4 ) ;
F_17 ( & V_44 -> V_49 , V_45 ) ;
F_18 ( & V_44 -> V_49 , V_46 ) ;
V_44 -> V_49 . V_50 = F_6 ( V_26 -> V_50 ) ;
V_44 -> V_49 . V_16 = V_44 -> V_5 . V_13 ;
V_44 -> V_5 . V_13 = F_6 ( V_43 ?
V_15 : V_14 ) ;
}
static struct V_3 * F_19 ( struct V_3 * V_51 ,
struct V_25 * V_26 ,
struct V_39 * V_40 )
{
int V_52 ;
unsigned char * V_28 , * V_29 ;
struct V_3 * V_4 ;
V_4 = F_9 ( V_51 , F_10 ( V_51 ) + V_30 , V_31 ) ;
if ( V_4 == NULL )
return NULL ;
F_12 ( V_4 ) ;
if ( V_4 -> V_32 == V_33 )
V_4 -> V_34 += V_30 ;
V_52 = V_53 ;
if ( V_26 -> V_36 )
V_52 += V_37 ;
V_29 = F_4 ( V_4 ) ;
V_28 = F_11 ( V_4 , V_30 ) ;
memmove ( V_28 , V_29 , V_52 ) ;
F_12 ( V_4 ) ;
F_16 ( V_4 , V_26 , V_40 , V_40 -> V_2 -> V_54 ) ;
return V_4 ;
}
static struct V_3 * F_20 ( struct V_25 * V_26 ,
struct V_39 * V_40 )
{
if ( V_26 -> V_42 )
return F_15 ( V_26 -> V_42 , V_31 ) ;
if ( ( V_40 -> type != V_47 ) && ( V_40 -> type != V_55 ) ) {
F_21 ( 1 , L_1 ) ;
return NULL ;
}
return F_19 ( V_26 -> V_41 , V_26 , V_40 ) ;
}
static void F_22 ( struct V_3 * V_4 , struct V_56 * V_57 ,
struct V_58 * V_59 )
{
bool V_60 ;
int V_61 ;
V_60 = ( V_4 -> V_62 == V_63 ) ;
F_23 ( V_59 , V_4 ) ;
F_8 ( V_4 , V_53 ) ;
V_61 = F_24 ( V_4 ) ;
if ( V_61 == V_64 ) {
V_57 -> V_65 . V_66 ++ ;
} else {
V_57 -> V_65 . V_67 ++ ;
V_57 -> V_65 . V_68 += V_4 -> V_48 ;
if ( V_60 )
V_57 -> V_65 . V_69 ++ ;
}
}
static int F_25 ( struct V_3 * V_4 , struct V_39 * V_40 ,
struct V_25 * V_26 )
{
if ( V_26 -> V_70 -> type == V_71 ) {
F_26 ( V_26 -> V_59 , V_4 , V_40 ) ;
F_27 ( F_13 ( V_4 ) -> V_72 , V_40 -> V_57 -> V_73 ) ;
}
return F_28 ( V_4 ) ;
}
static void F_29 ( struct V_25 * V_26 )
{
struct V_39 * V_40 ;
struct V_3 * V_4 ;
F_30 (frame->port_rcv->hsr, port) {
if ( V_40 == V_26 -> V_70 )
continue;
if ( ( V_40 -> type == V_71 ) && ! V_26 -> V_74 )
continue;
if ( ( V_40 -> type != V_71 ) && V_26 -> V_75 )
continue;
if ( F_31 ( V_40 , V_26 -> V_59 ,
V_26 -> V_50 ) )
continue;
if ( V_26 -> V_76 && ( V_40 -> type == V_71 ) ) {
F_32 ( V_26 -> V_42 ,
V_26 -> V_59 ,
V_26 -> V_70 ) ;
continue;
}
if ( V_40 -> type != V_71 )
V_4 = F_20 ( V_26 , V_40 ) ;
else
V_4 = F_14 ( V_26 , V_40 ) ;
if ( V_4 == NULL ) {
continue;
}
V_4 -> V_57 = V_40 -> V_57 ;
if ( V_40 -> type == V_71 )
F_22 ( V_4 , V_40 -> V_57 , V_26 -> V_59 ) ;
else
F_25 ( V_4 , V_40 , V_26 ) ;
}
}
static void F_33 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_25 * V_26 )
{
if ( F_34 ( V_2 , F_13 ( V_4 ) -> V_11 ) ) {
V_26 -> V_75 = true ;
V_4 -> V_62 = V_77 ;
} else {
V_26 -> V_75 = false ;
}
if ( ( V_4 -> V_62 == V_77 ) ||
( V_4 -> V_62 == V_63 ) ||
( V_4 -> V_62 == V_78 ) ) {
V_26 -> V_74 = true ;
} else {
V_26 -> V_74 = false ;
}
}
static int F_35 ( struct V_25 * V_26 ,
struct V_3 * V_4 , struct V_39 * V_40 )
{
struct V_5 * V_5 ;
unsigned long V_79 ;
V_26 -> V_76 = F_1 ( V_40 -> V_2 , V_4 ) ;
V_26 -> V_59 = F_36 ( & V_40 -> V_2 -> V_80 , V_4 ,
V_26 -> V_76 ) ;
if ( V_26 -> V_59 == NULL )
return - 1 ;
V_5 = (struct V_5 * ) F_4 ( V_4 ) ;
V_26 -> V_36 = false ;
if ( V_5 -> V_13 == F_6 ( V_81 ) ) {
V_26 -> V_36 = true ;
F_21 ( 1 , L_2 ) ;
}
if ( V_5 -> V_13 == F_6 ( V_14 )
|| V_5 -> V_13 == F_6 ( V_15 ) ) {
V_26 -> V_41 = NULL ;
V_26 -> V_42 = V_4 ;
V_26 -> V_50 = F_37 ( V_4 ) ;
} else {
V_26 -> V_41 = V_4 ;
V_26 -> V_42 = NULL ;
F_38 ( & V_40 -> V_2 -> V_82 , V_79 ) ;
V_26 -> V_50 = V_40 -> V_2 -> V_50 ;
V_40 -> V_2 -> V_50 ++ ;
F_39 ( & V_40 -> V_2 -> V_82 , V_79 ) ;
}
V_26 -> V_70 = V_40 ;
F_33 ( V_40 -> V_2 , V_4 , V_26 ) ;
return 0 ;
}
void F_40 ( struct V_3 * V_4 , struct V_39 * V_40 )
{
struct V_25 V_26 ;
if ( F_4 ( V_4 ) != V_4 -> V_83 ) {
F_21 ( 1 , L_3 ,
__FILE__ , __LINE__ , V_40 -> V_57 -> V_84 ) ;
goto V_85;
}
if ( F_35 ( & V_26 , V_4 , V_40 ) < 0 )
goto V_85;
F_41 ( V_26 . V_59 , V_40 , V_26 . V_50 ) ;
F_29 ( & V_26 ) ;
if ( V_26 . V_42 != NULL )
F_42 ( V_26 . V_42 ) ;
if ( V_26 . V_41 != NULL )
F_42 ( V_26 . V_41 ) ;
return;
V_85:
V_40 -> V_57 -> V_65 . V_86 ++ ;
F_42 ( V_4 ) ;
}
