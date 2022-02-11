void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 ;
F_2 ( L_1 ,
V_2 -> V_6 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_7 ; V_3 ++ ) {
V_5 = & V_2 -> V_8 [ V_3 ] ;
F_2 ( L_2
L_3
L_4 , V_3 , V_5 -> V_9 , V_5 -> V_10 ,
V_5 -> V_11 , V_5 -> V_12 , V_5 -> V_13 ,
V_5 -> V_14 ) ;
}
}
void F_3 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_15 * V_16 ;
F_2 ( L_5 ,
V_2 -> V_6 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_10 ; V_3 ++ ) {
V_16 = & V_2 -> V_17 [ V_3 ] ;
F_2 ( L_6
L_7 , V_3 , V_16 -> V_11 ,
V_16 -> V_18 , V_16 -> V_19 , V_16 -> V_14 ) ;
}
}
static void F_4 (
struct V_1 * V_2 ,
T_1 type )
{
T_2 V_3 , V_7 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_7 ; V_3 ++ ) {
if ( V_2 -> V_8 [ V_3 ] . type != V_20 )
continue;
V_2 -> V_8 [ V_3 ] . V_13 = V_7 ++ ;
}
}
static void F_5 (
struct V_1 * V_2 ,
T_1 type )
{
T_2 V_3 , V_19 = 0 , V_14 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_10 ; V_3 ++ ) {
V_21:
if ( V_2 -> V_17 [ V_3 ] . V_14 == V_14 ) {
V_2 -> V_17 [ V_3 ] . V_19 = V_19 ++ ;
continue;
}
V_14 ++ ;
V_19 = 0 ;
goto V_21;
}
}
static void F_6 ( T_2 * V_22 , T_2 V_23 )
{
int V_3 , V_24 , V_25 ;
if ( V_23 == 1 ) {
V_22 [ 0 ] = 0 ;
return;
}
for ( V_3 = 0 ; V_3 < V_23 ; V_3 ++ ) {
V_21:
F_7 ( & V_24 , sizeof( T_2 ) ) ;
V_24 = ( 1 + ( int ) ( 9999 + 1 ) - V_24 ) % V_23 ;
for ( V_25 = 0 ; V_25 < V_3 + 1 ; V_25 ++ ) {
V_24 |= 0x80000000 ;
if ( ( V_22 [ V_25 ] & 0x80000000 ) && ( V_22 [ V_25 ] == V_24 ) )
goto V_21;
}
V_22 [ V_3 ] = V_24 ;
}
for ( V_3 = 0 ; V_3 < V_23 ; V_3 ++ )
V_22 [ V_3 ] &= ~ 0x80000000 ;
}
static int F_8 (
struct V_1 * V_2 ,
T_1 type )
{
int V_3 = 0 ;
T_2 * V_22 , V_10 , V_7 = 0 , V_14 = 0 , V_26 = 0 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_10 ; V_10 ++ ) {
V_21:
if ( V_2 -> V_17 [ V_10 ] . V_14 == V_14 ) {
V_7 ++ ;
continue;
}
V_22 = F_9 ( V_7 * sizeof( T_2 ) , V_27 ) ;
if ( ! V_22 ) {
F_10 ( L_8
L_9 ) ;
return - 1 ;
}
F_6 ( V_22 , V_7 ) ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ )
V_2 -> V_17 [ V_26 + V_3 ] . V_19 = V_22 [ V_3 ] ;
F_11 ( V_22 ) ;
V_26 += V_7 ;
V_7 = 0 ;
V_14 ++ ;
goto V_21;
}
if ( V_7 ) {
V_22 = F_9 ( V_7 * sizeof( T_2 ) , V_27 ) ;
if ( ! V_22 ) {
F_10 ( L_10
L_11 ) ;
return - 1 ;
}
F_6 ( V_22 , V_7 ) ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ )
V_2 -> V_17 [ V_26 + V_3 ] . V_19 = V_22 [ V_3 ] ;
F_11 ( V_22 ) ;
}
return 0 ;
}
static int F_12 (
struct V_1 * V_2 ,
T_1 type )
{
int V_3 , V_24 = 0 ;
T_2 * V_22 , V_7 = V_2 -> V_7 ;
if ( ( type == V_28 ) || ( type == V_29 ) )
V_7 -- ;
else if ( type == V_30 )
V_7 -= 2 ;
if ( ! V_7 )
return 0 ;
V_22 = F_9 ( V_7 * sizeof( T_2 ) , V_27 ) ;
if ( ! V_22 ) {
F_10 ( L_12 ) ;
return - 1 ;
}
F_6 ( V_22 , V_7 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_7 ; V_3 ++ ) {
if ( V_2 -> V_8 [ V_3 ] . type != V_20 )
continue;
V_2 -> V_8 [ V_3 ] . V_13 = V_22 [ V_24 ++ ] ;
}
F_11 ( V_22 ) ;
return 0 ;
}
static void F_13 (
struct V_1 * V_2 ,
struct V_31 * V_32 ,
T_2 * V_7 ,
T_2 * V_10 )
{
int V_33 = 0 ;
T_2 V_34 = 0 , V_11 = 0 ;
T_2 V_35 = 0 ;
struct V_36 * V_37 = V_2 -> V_37 ;
if ( ( V_32 -> type == V_28 ) ||
( V_32 -> type == V_30 ) )
V_33 = 1 ;
if ( ( V_32 -> type == V_29 ) ||
( V_32 -> type == V_30 ) )
V_35 = ( V_2 -> V_38 >
V_37 -> V_39 -> V_40 -> V_41 ) ?
V_37 -> V_39 -> V_40 -> V_41 : V_2 -> V_38 ;
while ( V_11 < V_2 -> V_38 ) {
* V_10 += 1 ;
if ( V_33 ) {
V_33 = 0 ;
V_11 += V_32 -> V_42 ;
* V_7 += 1 ;
if ( V_35 )
V_35 -=
V_32 -> V_42 ;
continue;
}
if ( V_35 > 0 ) {
if ( ( V_11 + V_37 -> V_43 -> V_44 )
>= V_2 -> V_38 ) {
V_35 -=
( V_2 -> V_38 - V_11 ) ;
V_11 += ( V_2 -> V_38 - V_11 ) ;
continue;
}
if ( ( V_11 + V_37 -> V_43 -> V_44 )
>= V_37 -> V_39 -> V_40 -> V_41 ) {
V_35 -=
( V_37 -> V_39 -> V_40 -> V_41 -
V_11 ) ;
V_11 += ( V_37 -> V_39 -> V_40 -> V_41 -
V_11 ) ;
V_34 = 0 ;
* V_7 += 1 ;
continue;
}
V_11 += V_37 -> V_43 -> V_44 ;
V_35 -=
V_37 -> V_43 -> V_44 ;
continue;
}
if ( ( V_11 + V_37 -> V_43 -> V_44 ) >=
V_2 -> V_38 ) {
V_11 += ( V_2 -> V_38 - V_11 ) ;
continue;
}
if ( ( V_34 + V_37 -> V_43 -> V_44 ) >=
V_37 -> V_39 -> V_40 -> V_45 ) {
V_11 += ( V_37 -> V_39 -> V_40 -> V_45 -
V_34 ) ;
V_34 = 0 ;
* V_7 += 1 ;
continue;
}
V_34 += V_37 -> V_43 -> V_44 ;
V_11 += V_37 -> V_43 -> V_44 ;
}
}
static int F_14 (
struct V_1 * V_2 ,
struct V_31 * V_32 )
{
int V_33 = 0 , V_46 , V_47 ;
T_2 V_34 = 0 , V_11 = 0 , V_3 = 0 ;
T_2 V_10 = 0 , V_14 = 0 , V_35 = 0 ;
struct V_36 * V_37 = V_2 -> V_37 ;
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_4 * V_5 = V_2 -> V_8 ;
V_46 = V_37 -> V_39 -> V_40 -> V_48 ;
V_47 = V_37 -> V_39 -> V_40 -> V_49 ;
if ( ( V_32 -> type == V_28 ) ||
( V_32 -> type == V_30 ) )
V_33 = 1 ;
if ( ( V_32 -> type == V_29 ) ||
( V_32 -> type == V_30 ) )
V_35 = ( V_2 -> V_38 >
V_37 -> V_39 -> V_40 -> V_41 ) ?
V_37 -> V_39 -> V_40 -> V_41 : V_2 -> V_38 ;
while ( V_11 < V_2 -> V_38 ) {
V_10 ++ ;
if ( ! V_46 ) {
V_16 [ V_3 ] . V_11 = V_11 ;
V_16 [ V_3 ] . V_14 = V_14 ;
}
if ( ! V_47 && ( V_10 == 1 ) ) {
V_5 [ V_14 ] . V_9 = V_3 ;
V_5 [ V_14 ] . V_14 = V_14 ;
V_5 [ V_14 ] . V_11 = V_11 ;
V_5 [ V_14 ] . V_50 = V_11 ;
}
if ( V_33 ) {
V_33 = 0 ;
if ( ! V_46 ) {
V_16 [ V_3 ] . type = V_51 ;
V_16 [ V_3 ++ ] . V_18 = V_32 -> V_42 ;
}
if ( ! V_47 ) {
V_5 [ V_14 ] . type = V_52 ;
V_5 [ V_14 ] . V_10 = 1 ;
V_5 [ V_14 ] . V_12 =
V_32 -> V_42 ;
}
V_11 += V_32 -> V_42 ;
V_10 = 0 ;
V_14 ++ ;
if ( V_35 )
V_35 -=
V_32 -> V_42 ;
continue;
}
if ( V_35 > 0 ) {
if ( ( V_11 +
V_37 -> V_43 -> V_44 ) >=
V_2 -> V_38 ) {
if ( ! V_46 ) {
V_16 [ V_3 ] . type = V_53 ;
V_16 [ V_3 ] . V_18 =
( V_2 -> V_38 - V_11 ) ;
}
if ( ! V_47 ) {
V_5 [ V_14 ] . type = V_54 ;
V_5 [ V_14 ] . V_10 = V_10 ;
V_5 [ V_14 ] . V_12 = ( V_34 +
( V_2 -> V_38 - V_11 ) ) ;
}
V_35 -=
( V_2 -> V_38 - V_11 ) ;
V_11 += ( V_2 -> V_38 - V_11 ) ;
continue;
}
if ( ( V_11 +
V_37 -> V_43 -> V_44 ) >=
V_37 -> V_39 -> V_40 -> V_41 ) {
if ( ! V_46 ) {
V_16 [ V_3 ] . type = V_53 ;
V_16 [ V_3 ++ ] . V_18 =
( V_37 -> V_39 -> V_40 -> V_41 -
V_11 ) ;
}
if ( ! V_47 ) {
V_5 [ V_14 ] . type = V_54 ;
V_5 [ V_14 ] . V_10 = V_10 ;
V_5 [ V_14 ] . V_12 = ( V_34 +
( V_37 -> V_39 -> V_40 -> V_41 -
V_11 ) ) ;
}
V_35 -=
( V_37 -> V_39 -> V_40 -> V_41 -
V_11 ) ;
V_11 += ( V_37 -> V_39 -> V_40 -> V_41 -
V_11 ) ;
V_34 = 0 ;
V_10 = 0 ;
V_14 ++ ;
continue;
}
if ( ! V_46 ) {
V_16 [ V_3 ] . type = V_53 ;
V_16 [ V_3 ++ ] . V_18 =
V_37 -> V_43 -> V_44 ;
}
V_34 += V_37 -> V_43 -> V_44 ;
V_11 += V_37 -> V_43 -> V_44 ;
V_35 -=
V_37 -> V_43 -> V_44 ;
continue;
}
if ( ( V_11 + V_37 -> V_43 -> V_44 ) >=
V_2 -> V_38 ) {
if ( ! V_46 ) {
V_16 [ V_3 ] . type = V_55 ;
V_16 [ V_3 ] . V_18 = ( V_2 -> V_38 - V_11 ) ;
}
if ( ! V_47 ) {
V_5 [ V_14 ] . type = V_20 ;
V_5 [ V_14 ] . V_10 = V_10 ;
V_5 [ V_14 ] . V_12 = ( V_34 +
( V_2 -> V_38 - V_11 ) ) ;
}
V_11 += ( V_2 -> V_38 - V_11 ) ;
continue;
}
if ( ( V_34 + V_37 -> V_43 -> V_44 ) >=
V_37 -> V_39 -> V_40 -> V_45 ) {
if ( ! V_46 ) {
V_16 [ V_3 ] . type = V_55 ;
V_16 [ V_3 ++ ] . V_18 =
( V_37 -> V_39 -> V_40 -> V_45 -
V_34 ) ;
}
if ( ! V_47 ) {
V_5 [ V_14 ] . type = V_20 ;
V_5 [ V_14 ] . V_10 = V_10 ;
V_5 [ V_14 ] . V_12 = ( V_34 +
( V_37 -> V_39 -> V_40 -> V_45 -
V_34 ) ) ;
}
V_11 += ( V_37 -> V_39 -> V_40 -> V_45 -
V_34 ) ;
V_34 = 0 ;
V_10 = 0 ;
V_14 ++ ;
continue;
}
if ( ! V_46 ) {
V_16 [ V_3 ] . type = V_55 ;
V_16 [ V_3 ++ ] . V_18 =
V_37 -> V_43 -> V_44 ;
}
V_34 += V_37 -> V_43 -> V_44 ;
V_11 += V_37 -> V_43 -> V_44 ;
}
if ( ! V_47 ) {
if ( V_32 -> V_56 & V_57 ) {
if ( V_32 -> V_58 & V_59 ) {
if ( F_12 ( V_2 , V_32 -> type )
< 0 )
return - 1 ;
} else
F_4 ( V_2 , V_32 -> type ) ;
} else if ( V_32 -> V_56 & V_60 ) {
if ( V_32 -> V_58 & V_61 ) {
if ( F_12 ( V_2 , V_32 -> type )
< 0 )
return - 1 ;
} else
F_4 ( V_2 , V_32 -> type ) ;
}
#if 0
iscsit_dump_seq_list(cmd);
#endif
}
if ( ! V_46 ) {
if ( V_32 -> V_56 & V_57 ) {
if ( V_32 -> V_58 & V_62 ) {
if ( F_8 ( V_2 , V_32 -> type )
< 0 )
return - 1 ;
} else
F_5 ( V_2 , V_32 -> type ) ;
} else if ( V_32 -> V_56 & V_60 ) {
if ( V_32 -> V_58 & V_63 ) {
if ( F_8 ( V_2 , V_32 -> type )
< 0 )
return - 1 ;
} else
F_5 ( V_2 , V_32 -> type ) ;
}
#if 0
iscsit_dump_pdu_list(cmd);
#endif
}
return 0 ;
}
int F_15 (
struct V_1 * V_2 ,
struct V_31 * V_32 )
{
T_2 V_10 = 0 , V_7 = 1 ;
struct V_36 * V_37 = V_2 -> V_37 ;
struct V_15 * V_16 = NULL ;
struct V_4 * V_5 = NULL ;
F_13 ( V_2 , V_32 , & V_7 , & V_10 ) ;
if ( ! V_37 -> V_39 -> V_40 -> V_49 ) {
V_5 = F_9 ( V_7 * sizeof( struct V_4 ) , V_64 ) ;
if ( ! V_5 ) {
F_10 ( L_13 ) ;
return - 1 ;
}
V_2 -> V_8 = V_5 ;
V_2 -> V_7 = V_7 ;
}
if ( ! V_37 -> V_39 -> V_40 -> V_48 ) {
V_16 = F_9 ( V_10 * sizeof( struct V_15 ) , V_64 ) ;
if ( ! V_16 ) {
F_10 ( L_14 ) ;
F_11 ( V_5 ) ;
return - 1 ;
}
V_2 -> V_17 = V_16 ;
V_2 -> V_10 = V_10 ;
}
return F_14 ( V_2 , V_32 ) ;
}
struct V_15 * F_16 (
struct V_1 * V_2 ,
T_2 V_11 ,
T_2 V_18 )
{
T_2 V_3 ;
struct V_15 * V_16 = NULL ;
if ( ! V_2 -> V_17 ) {
F_10 ( L_15 ) ;
return NULL ;
}
V_16 = & V_2 -> V_17 [ 0 ] ;
for ( V_3 = 0 ; V_3 < V_2 -> V_10 ; V_3 ++ )
if ( ( V_16 [ V_3 ] . V_11 == V_11 ) && ( V_16 [ V_3 ] . V_18 == V_18 ) )
return & V_16 [ V_3 ] ;
F_10 ( L_16
L_17 , V_2 -> V_6 , V_11 , V_18 ) ;
return NULL ;
}
struct V_15 * F_17 (
struct V_1 * V_2 ,
struct V_4 * V_5 )
{
T_2 V_3 ;
struct V_36 * V_37 = V_2 -> V_37 ;
struct V_15 * V_16 = NULL ;
if ( ! V_2 -> V_17 ) {
F_10 ( L_15 ) ;
return NULL ;
}
if ( V_37 -> V_39 -> V_40 -> V_49 ) {
V_21:
V_16 = & V_2 -> V_17 [ V_2 -> V_9 ] ;
for ( V_3 = 0 ; V_16 [ V_3 ] . V_14 != V_2 -> V_14 ; V_3 ++ ) {
#if 0
pr_debug("pdu[i].seq_no: %d, pdu[i].pdu"
"_send_order: %d, pdu[i].offset: %d,"
" pdu[i].length: %d\n", pdu[i].seq_no,
pdu[i].pdu_send_order, pdu[i].offset,
pdu[i].length);
#endif
if ( V_16 [ V_3 ] . V_19 == V_2 -> V_19 ) {
V_2 -> V_19 ++ ;
return & V_16 [ V_3 ] ;
}
}
V_2 -> V_9 += V_2 -> V_19 ;
V_2 -> V_19 = 0 ;
V_2 -> V_14 ++ ;
if ( V_2 -> V_9 < V_2 -> V_10 )
goto V_21;
F_10 ( L_18
L_19 ,
V_2 -> V_6 , V_2 -> V_19 ) ;
return NULL ;
} else {
if ( ! V_5 ) {
F_10 ( L_20 ) ;
return NULL ;
}
#if 0
pr_debug("seq->pdu_start: %d, seq->pdu_count: %d,"
" seq->seq_no: %d\n", seq->pdu_start, seq->pdu_count,
seq->seq_no);
#endif
V_16 = & V_2 -> V_17 [ V_5 -> V_9 ] ;
if ( V_5 -> V_19 == V_5 -> V_10 ) {
F_10 ( L_21
L_22 ,
V_2 -> V_6 , V_5 -> V_19 ,
V_5 -> V_10 ) ;
return NULL ;
}
for ( V_3 = 0 ; V_3 < V_5 -> V_10 ; V_3 ++ ) {
if ( V_16 [ V_3 ] . V_19 == V_5 -> V_19 ) {
V_5 -> V_19 ++ ;
return & V_16 [ V_3 ] ;
}
}
F_10 ( L_23
L_24 ,
V_2 -> V_6 , V_5 -> V_19 ) ;
return NULL ;
}
return NULL ;
}
struct V_4 * F_18 (
struct V_1 * V_2 ,
T_2 V_11 ,
T_2 V_18 )
{
T_2 V_3 ;
if ( ! V_2 -> V_8 ) {
F_10 ( L_25 ) ;
return NULL ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_7 ; V_3 ++ ) {
#if 0
pr_debug("seq_list[i].orig_offset: %d, seq_list[i]."
"xfer_len: %d, seq_list[i].seq_no %u\n",
cmd->seq_list[i].orig_offset, cmd->seq_list[i].xfer_len,
cmd->seq_list[i].seq_no);
#endif
if ( ( V_2 -> V_8 [ V_3 ] . V_50 +
V_2 -> V_8 [ V_3 ] . V_12 ) >=
( V_11 + V_18 ) )
return & V_2 -> V_8 [ V_3 ] ;
}
F_10 ( L_26
L_27 , V_2 -> V_6 , V_11 ,
V_18 ) ;
return NULL ;
}
